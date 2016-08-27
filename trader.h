/////////////////////////////////////////////////////////////////////////
//// Ftdc C++ => C Adapter
//// Author : shawn666.liu@hotmail.com   
//// Generated at 2016/8/27 10:26:20
/////////////////////////////////////////////////////////////////////////

#pragma once
#include <USTPFtdcTraderApi.h>
#include "enums.h"

class Trader : public CUstpFtdcTraderSpi
{
public:
	CUstpFtdcTraderApi* RawApi{ nullptr };
	CbOnErrRtnEvent mOnErrRtnEvent{ nullptr };
	CbOnFrontEvent mOnFrontEvent{ nullptr };
	CbOnPackageEvent mOnPackageEvent{ nullptr };
	CbOnRspEvent mOnRspEvent{ nullptr };
	CbOnRtnEvent mOnRtnEvent{ nullptr };
	void* pObject;

	Trader(const char* pszFlowPath) {
		RawApi = CUstpFtdcTraderApi::CreateFtdcTraderApi(pszFlowPath);
		RawApi->RegisterSpi(this);
		pObject = this;
	}


	virtual ~Trader() {
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
	virtual void OnRspUserPasswordUpdate(CUstpFtdcUserPasswordUpdateField* pUserPasswordUpdate, CUstpFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspUserPasswordUpdate, pUserPasswordUpdate, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspOrderInsert(CUstpFtdcInputOrderField* pInputOrder, CUstpFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspOrderInsert, pInputOrder, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspOrderAction(CUstpFtdcOrderActionField* pOrderAction, CUstpFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspOrderAction, pOrderAction, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQuoteInsert(CUstpFtdcInputQuoteField* pInputQuote, CUstpFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQuoteInsert, pInputQuote, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQuoteAction(CUstpFtdcQuoteActionField* pQuoteAction, CUstpFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQuoteAction, pQuoteAction, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspForQuote(CUstpFtdcReqForQuoteField* pReqForQuote, CUstpFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspForQuote, pReqForQuote, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspMarginCombAction(CUstpFtdcInputMarginCombActionField* pInputMarginCombAction, CUstpFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspMarginCombAction, pInputMarginCombAction, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspUserDeposit(CUstpFtdcstpUserDepositField* pstpUserDeposit, CUstpFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspUserDeposit, pstpUserDeposit, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspTransferMoney(CUstpFtdcstpTransferMoneyField* pstpTransferMoney, CUstpFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspTransferMoney, pstpTransferMoney, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRtnFlowMessageCancel(CUstpFtdcFlowMessageCancelField* pFlowMessageCancel) {
		mOnRtnEvent(pObject, (int)EnumOnRtnEvent::OnRtnFlowMessageCancel, pFlowMessageCancel);
	};
	virtual void OnRtnTrade(CUstpFtdcTradeField* pTrade) {
		mOnRtnEvent(pObject, (int)EnumOnRtnEvent::OnRtnTrade, pTrade);
	};
	virtual void OnRtnOrder(CUstpFtdcOrderField* pOrder) {
		mOnRtnEvent(pObject, (int)EnumOnRtnEvent::OnRtnOrder, pOrder);
	};
	virtual void OnErrRtnOrderInsert(CUstpFtdcInputOrderField* pInputOrder, CUstpFtdcRspInfoField* pRspInfo) {
		mOnErrRtnEvent(pObject, (int)EnumOnErrRtnEvent::OnErrRtnOrderInsert, pInputOrder, pRspInfo);
	};
	virtual void OnErrRtnOrderAction(CUstpFtdcOrderActionField* pOrderAction, CUstpFtdcRspInfoField* pRspInfo) {
		mOnErrRtnEvent(pObject, (int)EnumOnErrRtnEvent::OnErrRtnOrderAction, pOrderAction, pRspInfo);
	};
	virtual void OnRtnInstrumentStatus(CUstpFtdcInstrumentStatusField* pInstrumentStatus) {
		mOnRtnEvent(pObject, (int)EnumOnRtnEvent::OnRtnInstrumentStatus, pInstrumentStatus);
	};
	virtual void OnRtnInvestorAccountDeposit(CUstpFtdcInvestorAccountDepositResField* pInvestorAccountDepositRes) {
		mOnRtnEvent(pObject, (int)EnumOnRtnEvent::OnRtnInvestorAccountDeposit, pInvestorAccountDepositRes);
	};
	virtual void OnRtnQuote(CUstpFtdcRtnQuoteField* pRtnQuote) {
		mOnRtnEvent(pObject, (int)EnumOnRtnEvent::OnRtnQuote, pRtnQuote);
	};
	virtual void OnErrRtnQuoteInsert(CUstpFtdcInputQuoteField* pInputQuote, CUstpFtdcRspInfoField* pRspInfo) {
		mOnErrRtnEvent(pObject, (int)EnumOnErrRtnEvent::OnErrRtnQuoteInsert, pInputQuote, pRspInfo);
	};
	virtual void OnErrRtnQuoteAction(CUstpFtdcOrderActionField* pOrderAction, CUstpFtdcRspInfoField* pRspInfo) {
		mOnErrRtnEvent(pObject, (int)EnumOnErrRtnEvent::OnErrRtnQuoteAction, pOrderAction, pRspInfo);
	};
	virtual void OnRtnForQuote(CUstpFtdcReqForQuoteField* pReqForQuote) {
		mOnRtnEvent(pObject, (int)EnumOnRtnEvent::OnRtnForQuote, pReqForQuote);
	};
	virtual void OnRtnMarginCombinationLeg(CUstpFtdcMarginCombinationLegField* pMarginCombinationLeg) {
		mOnRtnEvent(pObject, (int)EnumOnRtnEvent::OnRtnMarginCombinationLeg, pMarginCombinationLeg);
	};
	virtual void OnRtnMarginCombAction(CUstpFtdcInputMarginCombActionField* pInputMarginCombAction) {
		mOnRtnEvent(pObject, (int)EnumOnRtnEvent::OnRtnMarginCombAction, pInputMarginCombAction);
	};
	virtual void OnRtnUserDeposit(CUstpFtdcstpUserDepositField* pstpUserDeposit) {
		mOnRtnEvent(pObject, (int)EnumOnRtnEvent::OnRtnUserDeposit, pstpUserDeposit);
	};
	virtual void OnRspQryOrder(CUstpFtdcOrderField* pOrder, CUstpFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryOrder, pOrder, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryTrade(CUstpFtdcTradeField* pTrade, CUstpFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryTrade, pTrade, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryUserInvestor(CUstpFtdcRspUserInvestorField* pRspUserInvestor, CUstpFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryUserInvestor, pRspUserInvestor, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryTradingCode(CUstpFtdcRspTradingCodeField* pRspTradingCode, CUstpFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryTradingCode, pRspTradingCode, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryInvestorAccount(CUstpFtdcRspInvestorAccountField* pRspInvestorAccount, CUstpFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryInvestorAccount, pRspInvestorAccount, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryInstrument(CUstpFtdcRspInstrumentField* pRspInstrument, CUstpFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryInstrument, pRspInstrument, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryExchange(CUstpFtdcRspExchangeField* pRspExchange, CUstpFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryExchange, pRspExchange, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryInvestorPosition(CUstpFtdcRspInvestorPositionField* pRspInvestorPosition, CUstpFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryInvestorPosition, pRspInvestorPosition, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspSubscribeTopic(CUstpFtdcDisseminationField* pDissemination, CUstpFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspSubscribeTopic, pDissemination, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryComplianceParam(CUstpFtdcRspComplianceParamField* pRspComplianceParam, CUstpFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryComplianceParam, pRspComplianceParam, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryTopic(CUstpFtdcDisseminationField* pDissemination, CUstpFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryTopic, pDissemination, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryInvestorFee(CUstpFtdcInvestorFeeField* pInvestorFee, CUstpFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryInvestorFee, pInvestorFee, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryInvestorMargin(CUstpFtdcInvestorMarginField* pInvestorMargin, CUstpFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryInvestorMargin, pInvestorMargin, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryInvestorCombPosition(CUstpFtdcRspInvestorCombPositionField* pRspInvestorCombPosition, CUstpFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryInvestorCombPosition, pRspInvestorCombPosition, pRspInfo, nRequestID, bIsLast);
	};
	virtual void OnRspQryInvestorLegPosition(CUstpFtdcRspInvestorLegPositionField* pRspInvestorLegPosition, CUstpFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast) {
		mOnRspEvent(pObject, (int)EnumOnRspEvent::OnRspQryInvestorLegPosition, pRspInvestorLegPosition, pRspInfo, nRequestID, bIsLast);
	};

}; // end of class