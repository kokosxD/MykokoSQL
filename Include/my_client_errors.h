#pragma once

// Enumerator used to represent a MySQL client error
enum class ClientError : unsigned short{

	// The first implemented client error
	FirstError = 0x07D0,

	// Invalid client error
	Invalid = 0xFFFF,

	// Unknown error
	Unknown = 0x07D0,

	// Can't create socket
	SocketCreate = 0x07D1,

	// Can't connect to local MySQL server through socket
	SocketConnect = 0x07D2,

	// Can't connect to MySQL server
	HostConnect = 0x07D3,

	// Can't create TCP/IP socket
	IPSocketCreate = 0x07D4,

	// Unknown MySQL server host
	UnknownHost = 0x07D5,

	// MySQL server has gone away
	ServerGone = 0x07D6,

	// Protocol mismatch
	ProtocolMismatch = 0x07D7,

	// MySQL client ran out of memory
	OutOfMemory = 0x07D8,

	// Wrong host info
	WrongHostInfo = 0x07D9,

	// Localhost via UNIX socket
	LocalHostConnection = 0x07DA,

	// Connection via TCP/IP
	TCPConnection = 0x07DB,

	// Error in server handshake
	ServerHandshake = 0x07DC,

	// Lost connection to MySQL server during query
	ServerLostConnection = 0x07DD,

	// Commands out of sync, you can't run this command now
	CommandsOutOfSync = 0x07DE,

	// Named pipe
	NamedPipeConnection = 0x07DF,

	// Can't wait for named pipe to host
	NamedPipeWait = 0x07E0,

	// Can't open named pipe to host
	NamedPipeOpen = 0x07E1,

	// Can't set state of named pipe to host
	NamedPipeSetState = 0x07E2,

	// Can't initialize character set
	InitializeCharacterSet = 0x07E3,

	// Got packet bigger than 'max_allowed_packet' bytes
	PacketTooLarge = 0x07E4,

	// Embedded server
	EmbeddedServer = 0x07E5,

	// Error on SHOW SLAVE STATUS
	ShowSlaveStatus = 0x07E6,

	// Error on SHOW SLAVE HOSTS
	ShowSlaveHosts = 0x07E7,

	// Error connecting to slave
	SlaveConnect = 0x07E8,

	// Error connecting to master
	MasterConnect = 0x07E9,

	// SSL connection error
	SSLConnection = 0x07EA,

	// Malformed packet
	MalformedPacket = 0x07EB,

	// This client library is licensed for MySQL servers with different license
	WrongLicense = 0x07EC,

	// Invalid use of null pointer
	NullPointer = 0x07ED,

	// Statement not prepared
	NoPreparedStatement = 0x07EE,

	// No data supplied for parameters in prepared statement
	NoPreparedStatementData = 0x07EF,

	// Data truncated
	DataTruncated = 0x07F0,

	// No parameters exist in the statement
	NoStatementParameters = 0x07F1,

	// Invalid parameter number
	InvalidParameterNumber = 0x07F2,

	// Can't send long data for non-string/non-binary data types
	BufferTooLong = 0x07F3,

	// Using unsupported buffer type
	UnsupportedBufferType = 0x07F4,

	// Shared memory
	SharedMemoryConnection = 0x07F5,

	// Can't open shared memory, client could not create request event
	SharedMemoryClientRequestEvent = 0x07F6,

	// Can't open shared memory, no answer event received from server
	SharedMemoryServerNoAnswerEvent = 0x07F7,

	// Can't open shared memory, server could not allocate file mapping
	SharedMemoryServerFileMappingAllocate = 0x07F8,

	// Can't open shared memory, server could not get pointer to file mapping
	SharedMemoryServerFileMappingPointer = 0x07F9,

	// Can't open shared memory, client could not allocate file mapping
	SharedMemoryClientFileMappingAllocate = 0x07FA,

	// Can't open shared memory, client could not get pointer to file mapping
	SharedMemoryClientFileMappingPointer = 0x07FB,

	// Can't open shared memory, client could not create event
	SharedMemoryClientCreateEvent = 0x07FC,

	// Can't open shared memory, no answer received from server
	SharedMemoryServerNoAnswer = 0x07FD,

	// Can't open shared memory, cannot send request event to server
	SharedMemoryRequestEvent = 0x07FE,

	// Wrong or unknown protocol
	UnknownProtocol = 0x07FF,

	// Invalid connection handle
	InvalidConnectionHandle = 0x0800,

	// Connection using old (pre-4.1.1) authentication protocol refused (client option 'secure_auth' enabled)
	OldAuthenticationProtocol = 0x0801,

	// Row retrieval was canceled by mysql_stmt_close() call
	FetchCanceled = 0x0802,

	// Attempt to read column without prior row fetch
	NoFetchedRow = 0x0803,

	// Prepared statement contains no metadata
	NoPreparedStatementMetadata = 0x0804,

	// Attempt to read a row while there is no result set associated with the statement
	NoResult = 0x0805,

	// This feature is not implemented yet
	NoImplemented = 0x0806,

	// Lost connection to MySQL server
	ServerLostConnectionExtended = 0x0807,

	// Statement closed indirectly because of a preceding call
	StatementClosed = 0x0808,

	// The number of columns in the result set differs from the number of bound buffers. You must reset the statement, rebind the result set columns, and execute the statement again
	NewStatementMetadata = 0x0809,

	// This handle is already connected. Use a separate handle for each connection
	AlreadyConnected = 0x080A,

	// Authentication plugin cannot be loaded
	AuthenticationPluginCannotLoad = 0x080B,

	// There is an attribute with the same name already
	DuplicatedConnectionAttribute = 0x080C,

	// Authentication plugin reported error
	AuthenticationPlugin = 0x080D,

	// Insecure API function call
	InsecureAPICall = 0x080E,

	// File name is too long
	FileNameTooLong = 0x080F,

	// Set FIPS mode ON/STRICT failed
	SSLFIPSMode = 0x0810,

	// Compression protocol not supported with asynchronous protocol
	CompressionProtocolNotSupported = 0x0811,

	// Connection failed due to wrongly configured compression algorithm
	CompressionWronglyConfigured = 0x0812,

	// SSO user not found, please perform SSO authentication using kerberos
	KerberosUserNotFound = 0x0813,

	// File request rejected due to restrictions on access
	LoadFileRejected = 0x0814,

	// Failed to determinate real path
	LoadRealPathFailed = 0x0815,

	// DNS SRV lookup failed
	DNSSRVLookupFailed = 0x0816,

	// The last implemented client error
	LastError = 0x0816
};