monitor RW
	integer readers = 0
	integer writers = 0
	condition OKtoRead, OKtoWrite;

operation StartRead
	if writers != 0 or not empty (OKtoWrite)
		waitC(OKtoRead)
	readers = readers + 1
	signalC(OKtoRead)

operation EndRead
	readers = readers - 1
	if readers = 0
		signalC(OKtoWrite)

operation StartWrite
	if writers != 0 or readers != 0
		waitC(OKtoWrite)
	writers = writers + 1

operation EndWrite
	writers = writers - 1
	if (empty(OKtoRead))
	then signalC(OKtoWrite)
	else signalC(OKtoRead)
