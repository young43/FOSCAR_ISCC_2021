
"use strict";

let NavDGPS = require('./NavDGPS.js');
let CfgNMEA6 = require('./CfgNMEA6.js');
let RxmSVSI = require('./RxmSVSI.js');
let UpdSOS_Ack = require('./UpdSOS_Ack.js');
let RxmALM = require('./RxmALM.js');
let RxmRAWX = require('./RxmRAWX.js');
let UpdSOS = require('./UpdSOS.js');
let RxmEPH = require('./RxmEPH.js');
let CfgRST = require('./CfgRST.js');
let CfgNMEA = require('./CfgNMEA.js');
let EsfRAW = require('./EsfRAW.js');
let Inf = require('./Inf.js');
let NavATT = require('./NavATT.js');
let NavDGPS_SV = require('./NavDGPS_SV.js');
let MgaGAL = require('./MgaGAL.js');
let CfgINF_Block = require('./CfgINF_Block.js');
let MonHW = require('./MonHW.js');
let EsfINS = require('./EsfINS.js');
let NavCLOCK = require('./NavCLOCK.js');
let RxmRAWX_Meas = require('./RxmRAWX_Meas.js');
let NavPVT = require('./NavPVT.js');
let CfgTMODE3 = require('./CfgTMODE3.js');
let EsfRAW_Block = require('./EsfRAW_Block.js');
let EsfSTATUS = require('./EsfSTATUS.js');
let CfgPRT = require('./CfgPRT.js');
let MonGNSS = require('./MonGNSS.js');
let RxmSVSI_SV = require('./RxmSVSI_SV.js');
let CfgSBAS = require('./CfgSBAS.js');
let NavVELECEF = require('./NavVELECEF.js');
let CfgDAT = require('./CfgDAT.js');
let TimTM2 = require('./TimTM2.js');
let EsfMEAS = require('./EsfMEAS.js');
let NavPOSECEF = require('./NavPOSECEF.js');
let NavSOL = require('./NavSOL.js');
let AidALM = require('./AidALM.js');
let Ack = require('./Ack.js');
let RxmRAW_SV = require('./RxmRAW_SV.js');
let EsfSTATUS_Sens = require('./EsfSTATUS_Sens.js');
let CfgUSB = require('./CfgUSB.js');
let MonVER_Extension = require('./MonVER_Extension.js');
let RxmSFRBX = require('./RxmSFRBX.js');
let CfgRATE = require('./CfgRATE.js');
let NavTIMEUTC = require('./NavTIMEUTC.js');
let NavSVINFO = require('./NavSVINFO.js');
let AidHUI = require('./AidHUI.js');
let CfgGNSS_Block = require('./CfgGNSS_Block.js');
let CfgMSG = require('./CfgMSG.js');
let AidEPH = require('./AidEPH.js');
let CfgNAVX5 = require('./CfgNAVX5.js');
let NavSBAS_SV = require('./NavSBAS_SV.js');
let CfgNAV5 = require('./CfgNAV5.js');
let NavSAT = require('./NavSAT.js');
let CfgCFG = require('./CfgCFG.js');
let NavSBAS = require('./NavSBAS.js');
let NavSAT_SV = require('./NavSAT_SV.js');
let NavTIMEGPS = require('./NavTIMEGPS.js');
let CfgNMEA7 = require('./CfgNMEA7.js');
let CfgGNSS = require('./CfgGNSS.js');
let NavPVT7 = require('./NavPVT7.js');
let RxmRAW = require('./RxmRAW.js');
let NavSVINFO_SV = require('./NavSVINFO_SV.js');
let NavVELNED = require('./NavVELNED.js');
let NavSTATUS = require('./NavSTATUS.js');
let RxmRTCM = require('./RxmRTCM.js');
let NavSVIN = require('./NavSVIN.js');
let MonHW6 = require('./MonHW6.js');
let NavPOSLLH = require('./NavPOSLLH.js');
let CfgINF = require('./CfgINF.js');
let HnrPVT = require('./HnrPVT.js');
let NavRELPOSNED = require('./NavRELPOSNED.js');
let CfgANT = require('./CfgANT.js');
let CfgDGNSS = require('./CfgDGNSS.js');
let RxmSFRB = require('./RxmSFRB.js');
let CfgHNR = require('./CfgHNR.js');
let MonVER = require('./MonVER.js');
let NavDOP = require('./NavDOP.js');

module.exports = {
  NavDGPS: NavDGPS,
  CfgNMEA6: CfgNMEA6,
  RxmSVSI: RxmSVSI,
  UpdSOS_Ack: UpdSOS_Ack,
  RxmALM: RxmALM,
  RxmRAWX: RxmRAWX,
  UpdSOS: UpdSOS,
  RxmEPH: RxmEPH,
  CfgRST: CfgRST,
  CfgNMEA: CfgNMEA,
  EsfRAW: EsfRAW,
  Inf: Inf,
  NavATT: NavATT,
  NavDGPS_SV: NavDGPS_SV,
  MgaGAL: MgaGAL,
  CfgINF_Block: CfgINF_Block,
  MonHW: MonHW,
  EsfINS: EsfINS,
  NavCLOCK: NavCLOCK,
  RxmRAWX_Meas: RxmRAWX_Meas,
  NavPVT: NavPVT,
  CfgTMODE3: CfgTMODE3,
  EsfRAW_Block: EsfRAW_Block,
  EsfSTATUS: EsfSTATUS,
  CfgPRT: CfgPRT,
  MonGNSS: MonGNSS,
  RxmSVSI_SV: RxmSVSI_SV,
  CfgSBAS: CfgSBAS,
  NavVELECEF: NavVELECEF,
  CfgDAT: CfgDAT,
  TimTM2: TimTM2,
  EsfMEAS: EsfMEAS,
  NavPOSECEF: NavPOSECEF,
  NavSOL: NavSOL,
  AidALM: AidALM,
  Ack: Ack,
  RxmRAW_SV: RxmRAW_SV,
  EsfSTATUS_Sens: EsfSTATUS_Sens,
  CfgUSB: CfgUSB,
  MonVER_Extension: MonVER_Extension,
  RxmSFRBX: RxmSFRBX,
  CfgRATE: CfgRATE,
  NavTIMEUTC: NavTIMEUTC,
  NavSVINFO: NavSVINFO,
  AidHUI: AidHUI,
  CfgGNSS_Block: CfgGNSS_Block,
  CfgMSG: CfgMSG,
  AidEPH: AidEPH,
  CfgNAVX5: CfgNAVX5,
  NavSBAS_SV: NavSBAS_SV,
  CfgNAV5: CfgNAV5,
  NavSAT: NavSAT,
  CfgCFG: CfgCFG,
  NavSBAS: NavSBAS,
  NavSAT_SV: NavSAT_SV,
  NavTIMEGPS: NavTIMEGPS,
  CfgNMEA7: CfgNMEA7,
  CfgGNSS: CfgGNSS,
  NavPVT7: NavPVT7,
  RxmRAW: RxmRAW,
  NavSVINFO_SV: NavSVINFO_SV,
  NavVELNED: NavVELNED,
  NavSTATUS: NavSTATUS,
  RxmRTCM: RxmRTCM,
  NavSVIN: NavSVIN,
  MonHW6: MonHW6,
  NavPOSLLH: NavPOSLLH,
  CfgINF: CfgINF,
  HnrPVT: HnrPVT,
  NavRELPOSNED: NavRELPOSNED,
  CfgANT: CfgANT,
  CfgDGNSS: CfgDGNSS,
  RxmSFRB: RxmSFRB,
  CfgHNR: CfgHNR,
  MonVER: MonVER,
  NavDOP: NavDOP,
};
