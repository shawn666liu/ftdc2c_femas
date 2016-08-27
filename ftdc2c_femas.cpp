/////////////////////////////////////////////////////////////////////////
//// Ftdc C++ => C Adapter
//// Author : shawn666.liu@hotmail.com   
//// Generated at 2016/8/27 10:26:20
/////////////////////////////////////////////////////////////////////////

#include "ftdc2c_femas.h"
#include "quoter.h"
#include "trader.h"

FTDC2C_API void MYDECL MdDestroyApi(void* pApi) {
	delete static_cast<Quoter*>(pApi);
}

FTDC2C_API void MYDECL MdRegisterCallback(void* pApi, CbOnFrontEvent c1, CbOnPackageEvent c2, CbOnRspEvent c3, CbOnRtnEvent c4, void* pObject) {
	Quoter *p = static_cast<Quoter*>(pApi);
	p->mOnFrontEvent = c1;
	p->mOnPackageEvent = c2;
	p->mOnRspEvent = c3;
	p->mOnRtnEvent = c4;
	if (pObject == nullptr)
		pObject = pApi;
	p->pObject = pObject;
}


FTDC2C_API void* MYDECL MdCreateApi(const char* pszFlowPath) {
	return new Quoter(pszFlowPath);
}

FTDC2C_API const char* MYDECL MdGetVersion(int& nMajorVersion, int& nMinorVersion) {
	return CUstpFtdcMduserApi::GetVersion(nMajorVersion, nMinorVersion);
}

FTDC2C_API void MYDECL MdInit(void* pApi) {
	(static_cast<Quoter*>(pApi))->RawApi->Init();
}

FTDC2C_API const char* MYDECL MdGetTradingDay(void* pApi) {
	return (static_cast<Quoter*>(pApi))->RawApi->GetTradingDay();
}

FTDC2C_API void MYDECL MdRegisterFront(void* pApi, char* pszFrontAddress) {
	(static_cast<Quoter*>(pApi))->RawApi->RegisterFront(pszFrontAddress);
}

FTDC2C_API void MYDECL MdRegisterNameServer(void* pApi, char* pszNsAddress) {
	(static_cast<Quoter*>(pApi))->RawApi->RegisterNameServer(pszNsAddress);
}

FTDC2C_API int MYDECL MdRegisterCertificateFile(void* pApi, const char* pszCertFileName, const char* pszKeyFileName, const char* pszCaFileName, const char* pszKeyFilePassword) {
	return (static_cast<Quoter*>(pApi))->RawApi->RegisterCertificateFile(pszCertFileName, pszKeyFileName, pszCaFileName, pszKeyFilePassword);
}

FTDC2C_API void MYDECL MdSubscribeMarketDataTopic(void* pApi, int nTopicID, USTP_TE_RESUME_TYPE nResumeType) {
	(static_cast<Quoter*>(pApi))->RawApi->SubscribeMarketDataTopic(nTopicID, nResumeType);
}

FTDC2C_API int MYDECL MdSubMarketData(void* pApi, char* ppInstrumentID[], int nCount) {
	return (static_cast<Quoter*>(pApi))->RawApi->SubMarketData(ppInstrumentID, nCount);
}

FTDC2C_API int MYDECL MdUnSubMarketData(void* pApi, char* ppInstrumentID[], int nCount) {
	return (static_cast<Quoter*>(pApi))->RawApi->UnSubMarketData(ppInstrumentID, nCount);
}

FTDC2C_API void MYDECL MdSetHeartbeatTimeout(void* pApi, unsigned int timeout) {
	(static_cast<Quoter*>(pApi))->RawApi->SetHeartbeatTimeout(timeout);
}

FTDC2C_API int MYDECL MdReqUserLogin(void* pApi, CUstpFtdcReqUserLoginField* pReqUserLogin, int nRequestID) {
	return (static_cast<Quoter*>(pApi))->RawApi->ReqUserLogin(pReqUserLogin, nRequestID);
}

FTDC2C_API int MYDECL MdReqUserLogout(void* pApi, CUstpFtdcReqUserLogoutField* pReqUserLogout, int nRequestID) {
	return (static_cast<Quoter*>(pApi))->RawApi->ReqUserLogout(pReqUserLogout, nRequestID);
}

FTDC2C_API int MYDECL MdReqSubscribeTopic(void* pApi, CUstpFtdcDisseminationField* pDissemination, int nRequestID) {
	return (static_cast<Quoter*>(pApi))->RawApi->ReqSubscribeTopic(pDissemination, nRequestID);
}

FTDC2C_API int MYDECL MdReqQryTopic(void* pApi, CUstpFtdcDisseminationField* pDissemination, int nRequestID) {
	return (static_cast<Quoter*>(pApi))->RawApi->ReqQryTopic(pDissemination, nRequestID);
}

FTDC2C_API int MYDECL MdReqSubMarketData(void* pApi, CUstpFtdcSpecificInstrumentField* pSpecificInstrument, int nRequestID) {
	return (static_cast<Quoter*>(pApi))->RawApi->ReqSubMarketData(pSpecificInstrument, nRequestID);
}

FTDC2C_API int MYDECL MdReqUnSubMarketData(void* pApi, CUstpFtdcSpecificInstrumentField* pSpecificInstrument, int nRequestID) {
	return (static_cast<Quoter*>(pApi))->RawApi->ReqUnSubMarketData(pSpecificInstrument, nRequestID);
}

FTDC2C_API void MYDECL TdDestroyApi(void* pApi) {
	delete static_cast<Trader*>(pApi);
}

FTDC2C_API void MYDECL TdRegisterCallback(void* pApi, CbOnErrRtnEvent c1, CbOnFrontEvent c2, CbOnPackageEvent c3, CbOnRspEvent c4, CbOnRtnEvent c5, void* pObject) {
	Trader *p = static_cast<Trader*>(pApi);
	p->mOnErrRtnEvent = c1;
	p->mOnFrontEvent = c2;
	p->mOnPackageEvent = c3;
	p->mOnRspEvent = c4;
	p->mOnRtnEvent = c5;
	if (pObject == nullptr)
		pObject = pApi;
	p->pObject = pObject;
}


FTDC2C_API void* MYDECL TdCreateApi(const char* pszFlowPath) {
	return new Trader(pszFlowPath);
}

FTDC2C_API const char* MYDECL TdGetVersion(int& nMajorVersion, int& nMinorVersion) {
	return CUstpFtdcTraderApi::GetVersion(nMajorVersion, nMinorVersion);
}

FTDC2C_API void MYDECL TdInit(void* pApi) {
	(static_cast<Trader*>(pApi))->RawApi->Init();
}

FTDC2C_API const char* MYDECL TdGetTradingDay(void* pApi) {
	return (static_cast<Trader*>(pApi))->RawApi->GetTradingDay();
}

FTDC2C_API void MYDECL TdRegisterFront(void* pApi, char* pszFrontAddress) {
	(static_cast<Trader*>(pApi))->RawApi->RegisterFront(pszFrontAddress);
}

FTDC2C_API void MYDECL TdRegisterNameServer(void* pApi, char* pszNsAddress) {
	(static_cast<Trader*>(pApi))->RawApi->RegisterNameServer(pszNsAddress);
}

FTDC2C_API int MYDECL TdRegisterCertificateFile(void* pApi, const char* pszCertFileName, const char* pszKeyFileName, const char* pszCaFileName, const char* pszKeyFilePassword) {
	return (static_cast<Trader*>(pApi))->RawApi->RegisterCertificateFile(pszCertFileName, pszKeyFileName, pszCaFileName, pszKeyFilePassword);
}

FTDC2C_API void MYDECL TdSubscribePrivateTopic(void* pApi, USTP_TE_RESUME_TYPE nResumeType) {
	(static_cast<Trader*>(pApi))->RawApi->SubscribePrivateTopic(nResumeType);
}

FTDC2C_API void MYDECL TdSubscribePublicTopic(void* pApi, USTP_TE_RESUME_TYPE nResumeType) {
	(static_cast<Trader*>(pApi))->RawApi->SubscribePublicTopic(nResumeType);
}

FTDC2C_API void MYDECL TdSubscribeUserTopic(void* pApi, USTP_TE_RESUME_TYPE nResumeType) {
	(static_cast<Trader*>(pApi))->RawApi->SubscribeUserTopic(nResumeType);
}

FTDC2C_API void MYDECL TdSubscribeForQuote(void* pApi, USTP_TE_RESUME_TYPE nResumeType) {
	(static_cast<Trader*>(pApi))->RawApi->SubscribeForQuote(nResumeType);
}

FTDC2C_API void MYDECL TdSetHeartbeatTimeout(void* pApi, unsigned int timeout) {
	(static_cast<Trader*>(pApi))->RawApi->SetHeartbeatTimeout(timeout);
}

FTDC2C_API int MYDECL TdOpenRequestLog(void* pApi, const char* pszReqLogFileName) {
	return (static_cast<Trader*>(pApi))->RawApi->OpenRequestLog(pszReqLogFileName);
}

FTDC2C_API int MYDECL TdOpenResponseLog(void* pApi, const char* pszRspLogFileName) {
	return (static_cast<Trader*>(pApi))->RawApi->OpenResponseLog(pszRspLogFileName);
}

FTDC2C_API int MYDECL TdReqUserLogin(void* pApi, CUstpFtdcReqUserLoginField* pReqUserLogin, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqUserLogin(pReqUserLogin, nRequestID);
}

FTDC2C_API int MYDECL TdReqUserLogout(void* pApi, CUstpFtdcReqUserLogoutField* pReqUserLogout, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqUserLogout(pReqUserLogout, nRequestID);
}

FTDC2C_API int MYDECL TdReqUserPasswordUpdate(void* pApi, CUstpFtdcUserPasswordUpdateField* pUserPasswordUpdate, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqUserPasswordUpdate(pUserPasswordUpdate, nRequestID);
}

FTDC2C_API int MYDECL TdReqOrderInsert(void* pApi, CUstpFtdcInputOrderField* pInputOrder, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqOrderInsert(pInputOrder, nRequestID);
}

FTDC2C_API int MYDECL TdReqOrderAction(void* pApi, CUstpFtdcOrderActionField* pOrderAction, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqOrderAction(pOrderAction, nRequestID);
}

FTDC2C_API int MYDECL TdReqQuoteInsert(void* pApi, CUstpFtdcInputQuoteField* pInputQuote, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQuoteInsert(pInputQuote, nRequestID);
}

FTDC2C_API int MYDECL TdReqQuoteAction(void* pApi, CUstpFtdcQuoteActionField* pQuoteAction, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQuoteAction(pQuoteAction, nRequestID);
}

FTDC2C_API int MYDECL TdReqForQuote(void* pApi, CUstpFtdcReqForQuoteField* pReqForQuote, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqForQuote(pReqForQuote, nRequestID);
}

FTDC2C_API int MYDECL TdReqMarginCombAction(void* pApi, CUstpFtdcInputMarginCombActionField* pInputMarginCombAction, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqMarginCombAction(pInputMarginCombAction, nRequestID);
}

FTDC2C_API int MYDECL TdReqUserDeposit(void* pApi, CUstpFtdcstpUserDepositField* pstpUserDeposit, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqUserDeposit(pstpUserDeposit, nRequestID);
}

FTDC2C_API int MYDECL TdReqTransferMoney(void* pApi, CUstpFtdcstpTransferMoneyField* pstpTransferMoney, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqTransferMoney(pstpTransferMoney, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryOrder(void* pApi, CUstpFtdcQryOrderField* pQryOrder, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryOrder(pQryOrder, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryTrade(void* pApi, CUstpFtdcQryTradeField* pQryTrade, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryTrade(pQryTrade, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryUserInvestor(void* pApi, CUstpFtdcQryUserInvestorField* pQryUserInvestor, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryUserInvestor(pQryUserInvestor, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryTradingCode(void* pApi, CUstpFtdcQryTradingCodeField* pQryTradingCode, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryTradingCode(pQryTradingCode, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryInvestorAccount(void* pApi, CUstpFtdcQryInvestorAccountField* pQryInvestorAccount, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryInvestorAccount(pQryInvestorAccount, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryInstrument(void* pApi, CUstpFtdcQryInstrumentField* pQryInstrument, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryInstrument(pQryInstrument, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryExchange(void* pApi, CUstpFtdcQryExchangeField* pQryExchange, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryExchange(pQryExchange, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryInvestorPosition(void* pApi, CUstpFtdcQryInvestorPositionField* pQryInvestorPosition, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryInvestorPosition(pQryInvestorPosition, nRequestID);
}

FTDC2C_API int MYDECL TdReqSubscribeTopic(void* pApi, CUstpFtdcDisseminationField* pDissemination, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqSubscribeTopic(pDissemination, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryComplianceParam(void* pApi, CUstpFtdcQryComplianceParamField* pQryComplianceParam, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryComplianceParam(pQryComplianceParam, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryTopic(void* pApi, CUstpFtdcDisseminationField* pDissemination, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryTopic(pDissemination, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryInvestorFee(void* pApi, CUstpFtdcQryInvestorFeeField* pQryInvestorFee, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryInvestorFee(pQryInvestorFee, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryInvestorMargin(void* pApi, CUstpFtdcQryInvestorMarginField* pQryInvestorMargin, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryInvestorMargin(pQryInvestorMargin, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryInvestorCombPosition(void* pApi, CUstpFtdcQryInvestorCombPositionField* pQryInvestorCombPosition, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryInvestorCombPosition(pQryInvestorCombPosition, nRequestID);
}

FTDC2C_API int MYDECL TdReqQryInvestorLegPosition(void* pApi, CUstpFtdcQryInvestorLegPositionField* pQryInvestorLegPosition, int nRequestID) {
	return (static_cast<Trader*>(pApi))->RawApi->ReqQryInvestorLegPosition(pQryInvestorLegPosition, nRequestID);
}

