/////////////////////////////////////////////////////////////////////////
//// Ftdc C++ => C Adapter
//// Author : shawn666.liu@hotmail.com   
//// Generated at 2016/8/27 10:26:20
/////////////////////////////////////////////////////////////////////////

#pragma once

#ifdef WIN32
// Windows
#ifdef FTDC2C_EXPORTS
#define FTDC2C_API extern __declspec(dllexport)
#else
#define FTDC2C_API extern __declspec(dllimport)
#endif
#define MYDECL	__stdcall
#else
// Linux
#define FTDC2C_API extern
#define MYDECL  __attribute__((stdcall))
#endif




#include <USTPFtdcUserApiStruct.h>

#ifdef __cplusplus
extern "C" {
#endif

	typedef void(MYDECL *CbOnErrRtnEvent)(void* pObject, int type, void* pParam, void* pRspInfo);
	typedef void(MYDECL *CbOnFrontEvent)(void* pObject, int type, int Reason);
	typedef void(MYDECL *CbOnRspEvent)(void* pObject, int type, void* pParam, void* pRspInfo, int nRequestID, bool bIsLast);
	typedef void(MYDECL *CbOnRtnEvent)(void* pObject, int type, void* pParam);
	typedef void(MYDECL *CbOnPackageEvent)(void* pObject, int type, int nTopicID, int nSequenceNo);

	FTDC2C_API void MYDECL MdDestroyApi(void* pApi);
	FTDC2C_API void MYDECL MdRegisterCallback(void* pApi, CbOnFrontEvent c1, CbOnPackageEvent c2, CbOnRspEvent c3, CbOnRtnEvent c4, void* pObject);
	FTDC2C_API void* MYDECL MdCreateApi(const char* pszFlowPath);
	FTDC2C_API const char* MYDECL MdGetVersion(int& nMajorVersion, int& nMinorVersion);
	FTDC2C_API void MYDECL MdInit(void* pApi);
	FTDC2C_API const char* MYDECL MdGetTradingDay(void* pApi);
	FTDC2C_API void MYDECL MdRegisterFront(void* pApi, char* pszFrontAddress);
	FTDC2C_API void MYDECL MdRegisterNameServer(void* pApi, char* pszNsAddress);
	FTDC2C_API int MYDECL MdRegisterCertificateFile(void* pApi, const char* pszCertFileName, const char* pszKeyFileName, const char* pszCaFileName, const char* pszKeyFilePassword);
	FTDC2C_API void MYDECL MdSubscribeMarketDataTopic(void* pApi, int nTopicID, USTP_TE_RESUME_TYPE nResumeType);
	FTDC2C_API int MYDECL MdSubMarketData(void* pApi, char* ppInstrumentID[], int nCount);
	FTDC2C_API int MYDECL MdUnSubMarketData(void* pApi, char* ppInstrumentID[], int nCount);
	FTDC2C_API void MYDECL MdSetHeartbeatTimeout(void* pApi, unsigned int timeout);
	FTDC2C_API int MYDECL MdReqUserLogin(void* pApi, CUstpFtdcReqUserLoginField* pReqUserLogin, int nRequestID);
	FTDC2C_API int MYDECL MdReqUserLogout(void* pApi, CUstpFtdcReqUserLogoutField* pReqUserLogout, int nRequestID);
	FTDC2C_API int MYDECL MdReqSubscribeTopic(void* pApi, CUstpFtdcDisseminationField* pDissemination, int nRequestID);
	FTDC2C_API int MYDECL MdReqQryTopic(void* pApi, CUstpFtdcDisseminationField* pDissemination, int nRequestID);
	FTDC2C_API int MYDECL MdReqSubMarketData(void* pApi, CUstpFtdcSpecificInstrumentField* pSpecificInstrument, int nRequestID);
	FTDC2C_API int MYDECL MdReqUnSubMarketData(void* pApi, CUstpFtdcSpecificInstrumentField* pSpecificInstrument, int nRequestID);

	FTDC2C_API void MYDECL TdDestroyApi(void* pApi);
	FTDC2C_API void MYDECL TdRegisterCallback(void* pApi, CbOnErrRtnEvent c1, CbOnFrontEvent c2, CbOnPackageEvent c3, CbOnRspEvent c4, CbOnRtnEvent c5, void* pObject);
	FTDC2C_API void* MYDECL TdCreateApi(const char* pszFlowPath);
	FTDC2C_API const char* MYDECL TdGetVersion(int& nMajorVersion, int& nMinorVersion);
	FTDC2C_API void MYDECL TdInit(void* pApi);
	FTDC2C_API const char* MYDECL TdGetTradingDay(void* pApi);
	FTDC2C_API void MYDECL TdRegisterFront(void* pApi, char* pszFrontAddress);
	FTDC2C_API void MYDECL TdRegisterNameServer(void* pApi, char* pszNsAddress);
	FTDC2C_API int MYDECL TdRegisterCertificateFile(void* pApi, const char* pszCertFileName, const char* pszKeyFileName, const char* pszCaFileName, const char* pszKeyFilePassword);
	FTDC2C_API void MYDECL TdSubscribePrivateTopic(void* pApi, USTP_TE_RESUME_TYPE nResumeType);
	FTDC2C_API void MYDECL TdSubscribePublicTopic(void* pApi, USTP_TE_RESUME_TYPE nResumeType);
	FTDC2C_API void MYDECL TdSubscribeUserTopic(void* pApi, USTP_TE_RESUME_TYPE nResumeType);
	FTDC2C_API void MYDECL TdSubscribeForQuote(void* pApi, USTP_TE_RESUME_TYPE nResumeType);
	FTDC2C_API void MYDECL TdSetHeartbeatTimeout(void* pApi, unsigned int timeout);
	FTDC2C_API int MYDECL TdOpenRequestLog(void* pApi, const char* pszReqLogFileName);
	FTDC2C_API int MYDECL TdOpenResponseLog(void* pApi, const char* pszRspLogFileName);
	FTDC2C_API int MYDECL TdReqUserLogin(void* pApi, CUstpFtdcReqUserLoginField* pReqUserLogin, int nRequestID);
	FTDC2C_API int MYDECL TdReqUserLogout(void* pApi, CUstpFtdcReqUserLogoutField* pReqUserLogout, int nRequestID);
	FTDC2C_API int MYDECL TdReqUserPasswordUpdate(void* pApi, CUstpFtdcUserPasswordUpdateField* pUserPasswordUpdate, int nRequestID);
	FTDC2C_API int MYDECL TdReqOrderInsert(void* pApi, CUstpFtdcInputOrderField* pInputOrder, int nRequestID);
	FTDC2C_API int MYDECL TdReqOrderAction(void* pApi, CUstpFtdcOrderActionField* pOrderAction, int nRequestID);
	FTDC2C_API int MYDECL TdReqQuoteInsert(void* pApi, CUstpFtdcInputQuoteField* pInputQuote, int nRequestID);
	FTDC2C_API int MYDECL TdReqQuoteAction(void* pApi, CUstpFtdcQuoteActionField* pQuoteAction, int nRequestID);
	FTDC2C_API int MYDECL TdReqForQuote(void* pApi, CUstpFtdcReqForQuoteField* pReqForQuote, int nRequestID);
	FTDC2C_API int MYDECL TdReqMarginCombAction(void* pApi, CUstpFtdcInputMarginCombActionField* pInputMarginCombAction, int nRequestID);
	FTDC2C_API int MYDECL TdReqUserDeposit(void* pApi, CUstpFtdcstpUserDepositField* pstpUserDeposit, int nRequestID);
	FTDC2C_API int MYDECL TdReqTransferMoney(void* pApi, CUstpFtdcstpTransferMoneyField* pstpTransferMoney, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryOrder(void* pApi, CUstpFtdcQryOrderField* pQryOrder, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryTrade(void* pApi, CUstpFtdcQryTradeField* pQryTrade, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryUserInvestor(void* pApi, CUstpFtdcQryUserInvestorField* pQryUserInvestor, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryTradingCode(void* pApi, CUstpFtdcQryTradingCodeField* pQryTradingCode, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryInvestorAccount(void* pApi, CUstpFtdcQryInvestorAccountField* pQryInvestorAccount, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryInstrument(void* pApi, CUstpFtdcQryInstrumentField* pQryInstrument, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryExchange(void* pApi, CUstpFtdcQryExchangeField* pQryExchange, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryInvestorPosition(void* pApi, CUstpFtdcQryInvestorPositionField* pQryInvestorPosition, int nRequestID);
	FTDC2C_API int MYDECL TdReqSubscribeTopic(void* pApi, CUstpFtdcDisseminationField* pDissemination, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryComplianceParam(void* pApi, CUstpFtdcQryComplianceParamField* pQryComplianceParam, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryTopic(void* pApi, CUstpFtdcDisseminationField* pDissemination, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryInvestorFee(void* pApi, CUstpFtdcQryInvestorFeeField* pQryInvestorFee, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryInvestorMargin(void* pApi, CUstpFtdcQryInvestorMarginField* pQryInvestorMargin, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryInvestorCombPosition(void* pApi, CUstpFtdcQryInvestorCombPositionField* pQryInvestorCombPosition, int nRequestID);
	FTDC2C_API int MYDECL TdReqQryInvestorLegPosition(void* pApi, CUstpFtdcQryInvestorLegPositionField* pQryInvestorLegPosition, int nRequestID);


#ifdef __cplusplus
}
#endif
