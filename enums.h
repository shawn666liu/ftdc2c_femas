/////////////////////////////////////////////////////////////////////////
//// Ftdc C++ => C Adapter
//// Author : shawn666.liu@hotmail.com   
//// Generated at 2016/8/27 10:26:20
/////////////////////////////////////////////////////////////////////////

#pragma once

/// <summary>
/// 所有的OnErrRtnXXXX回调事件
/// </summary>
enum class EnumOnErrRtnEvent
{
	None,
	OnErrRtnOrderInsert,
	OnErrRtnOrderAction,
	OnErrRtnQuoteInsert,
	OnErrRtnQuoteAction,
};

/// <summary>
/// 所有的OnFrontXXXX回调事件
/// </summary>
enum class EnumOnFrontEvent
{
	None,
	OnFrontConnected,
	OnFrontDisconnected,
};

/// <summary>
/// 所有的OnPackageXXXX回调事件
/// </summary>
enum class EnumOnPackageEvent
{
	None,
	OnPackageStart,
	OnPackageEnd,
};

/// <summary>
/// 所有的OnRspXXXX回调事件
/// </summary>
enum class EnumOnRspEvent
{
	None,
	OnRspError,
	OnRspUserLogin,
	OnRspUserLogout,
	OnRspSubscribeTopic,
	OnRspQryTopic,
	OnRspSubMarketData,
	OnRspUnSubMarketData,
	OnRspUserPasswordUpdate,
	OnRspOrderInsert,
	OnRspOrderAction,
	OnRspQuoteInsert,
	OnRspQuoteAction,
	OnRspForQuote,
	OnRspMarginCombAction,
	OnRspUserDeposit,
	OnRspTransferMoney,
	OnRspQryOrder,
	OnRspQryTrade,
	OnRspQryUserInvestor,
	OnRspQryTradingCode,
	OnRspQryInvestorAccount,
	OnRspQryInstrument,
	OnRspQryExchange,
	OnRspQryInvestorPosition,
	OnRspQryComplianceParam,
	OnRspQryInvestorFee,
	OnRspQryInvestorMargin,
	OnRspQryInvestorCombPosition,
	OnRspQryInvestorLegPosition,
};

/// <summary>
/// 所有的OnRtnXXXX回调事件
/// </summary>
enum class EnumOnRtnEvent
{
	None,
	OnRtnDepthMarketData,
	OnRtnFlowMessageCancel,
	OnRtnTrade,
	OnRtnOrder,
	OnRtnInstrumentStatus,
	OnRtnInvestorAccountDeposit,
	OnRtnQuote,
	OnRtnForQuote,
	OnRtnMarginCombinationLeg,
	OnRtnMarginCombAction,
	OnRtnUserDeposit,
};

