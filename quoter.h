/////////////////////////////////////////////////////////////////////////
//// Ftdc C++ => C Adapter
//// Author : shawn666.liu@hotmail.com   
//// Generated at 2016/8/27 10:26:20
/////////////////////////////////////////////////////////////////////////

#pragma once
#include <USTPFtdcMduserApi.h>
#include "enums.h"

class Quoter : public CUstpFtdcMduserSpi
{
public:
	CUstpFtdcMduserApi* RawApi{ nullptr };
	CbOnFrontEvent mOnFrontEvent{ nullptr };
	CbOnPackageEvent mOnPackageEvent{ nullptr };
	CbOnRspEvent mOnRspEvent{ nullptr };
	CbOnRtnEvent mOnRtnEvent{ nullptr };
	void* pObject;

	Quoter(const char* pszFlowPath) {
		RawApi = CUstpFtdcMduserApi::CreateFtdcMduserApi(pszFlowPath);
		RawApi->RegisterSpi(this);
		pObject = this;
	}


	virtual ~Quoter() {
		if (RawApi){
			RawApi->RegisterSpi(nullptr);
			RawApi->Release();
			RawApi = nullptr;
		}
	};

	virtual void OnFrontConnected() {
		mOnFrontEvent(pObject, (int)EnumOnFrontEvent::OnFrontConnected, 0);
	};
	virtual void OnFrontDisconnected(int nReason) {
		mOnFrontEvent(pObject, (int)EnumOnFrontEvent::OnFrontDisconnected, nReason);
	};
	virtual void OnHeartBeatWarning(int nTimeLapse) {
	};
	virtual void OnPackageStart(int nTopicID, int nSequenceNo) {
		mOnPackageEvent(pObject, (int)EnumOnPackageEvent::OnPackageStart, nTopicID, nSequenceNo);
	};
	virtual void OnPackageEnd(int nTopicID, int nSequenceNo) {
		mOnPackageEvent(pObject, (int)EnumOnPackageEvent::OnPackageEnd, nTopicID, nSequenceNo);
	};
	virtual void OnRspError(CUstpFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspError, nullptr, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspUserLogin(CUstpFtdcRspUserLoginField* pRspUserLogin, CUstpFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspUserLogin, pRspUserLogin, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspUserLogout(CUstpFtdcRspUserLogoutField* pRspUserLogout, CUstpFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspUserLogout, pRspUserLogout, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspSubscribeTopic(CUstpFtdcDisseminationField* pDissemination, CUstpFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspSubscribeTopic, pDissemination, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryTopic(CUstpFtdcDisseminationField* pDissemination, CUstpFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryTopic, pDissemination, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRtnDepthMarketData(CUstpFtdcDepthMarketDataField* pDepthMarketData) {
		mOnRtnEvent(pObject, (int)EnumOnRtnEvent::OnRtnDepthMarketData, pDepthMarketData);
	};
	virtual void OnRspSubMarketData(CUstpFtdcSpecificInstrumentField* pSpecificInstrument, CUstpFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspSubMarketData, pSpecificInstrument, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspUnSubMarketData(CUstpFtdcSpecificInstrumentField* pSpecificInstrument, CUstpFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspUnSubMarketData, pSpecificInstrument, pRspInfo, nRequestID, bIsLast);
	};

}; // end of class