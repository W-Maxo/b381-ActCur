#ifndef	_DEVTYPES__H_
#define	_DEVTYPES__H_ 1

// тип внутренних регистров устройства
enum CRegType 
{
	rt8 = 0, 
	rt16,
	rt32,
	rt64
};

// тип устройства
enum CDeviceType 
{	
	dtUndefined,
	dtNULL,
	dtAnalyzer,
	dtGenerator,
	dtOscilloscope,
	dtViking,
	dtManom,
	dtGIVI,
	dtADC0
};


// универсальный идентификатор устройства
struct CDeviceID
{
	CDeviceType m_DeviceType;
	ULONG m_nDeviceVersion;
	ULONG m_nBaseAddress;
	int	m_nIRQ;
	ULONG m_nVendorID;
};

// CallBack для нотификации всех пользователей устройство
// Первый параметр - пользоваель-инициатор, второй параметр - команда
typedef void (*PDrvCallBack) (int nHandle , int nCommand);

#endif