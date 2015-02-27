#ifndef WINSERIAL_H
#define WINSERIAL_H

/*
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
 
#include <stdexcept>
#include <Windows.h>

class WinSerial
{
public:    
    WinSerial(LPCTSTR port, 
        DWORD baud = CBR_9600 , 
        BYTE stopbits = ONESTOPBIT, 
        BYTE parity = NOPARITY,
        BYTE ByteSize = 8);
    
    LPCTSTR Port();

    VOID Open();
    VOID Close();   

    DWORD InWaiting();
    DWORD Write(LPCVOID src, DWORD nbytes);
    DWORD Read(LPVOID dst, DWORD nbytes);
private:
    TCHAR port_[MAX_PATH + 1];
    DWORD baud_;
    BYTE stopbits_;
    BYTE parity_;
    BYTE ByteSize_;

    HANDLE handle_;
};

class WinSerialException : public std::runtime_error 
{
public:
    WinSerialException(const std::string & reason);
    ~WinSerialException();
    static void Throw(const std::string & reason);
};

#endif