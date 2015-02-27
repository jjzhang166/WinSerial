#WinSerial
  general code for windows serial port in C++, simple read & write.

usage:

	WinSerial serial(_T("COM1"));
	
	try {
		serial.Open();		
		
		serial.Write("HELLO WORLD", 11);
		
		...
		
		while (serial.InWaiting()) {
            ...		
			serial.Read(&ch, 1);
		}
		
		...
		
		serial.Close();
	} catch (WinSerialException & ex) {
		std::cerr << ex.what() << std::endl;
	}
	
dependent:
	Shlwapi.lib