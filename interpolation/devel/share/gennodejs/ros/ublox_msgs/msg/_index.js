
"use strict";

let CfgGNSS_Block = require('./CfgGNSS_Block.js');
let AidEPH = require('./AidEPH.js');
let CfgNAV5 = require('./CfgNAV5.js');
let NavCLOCK = require('./NavCLOCK.js');
let CfgHNR = require('./CfgHNR.js');
let EsfSTATUS_Sens = require('./EsfSTATUS_Sens.js');
let NavTIMEGPS = require('./NavTIMEGPS.js');
let CfgINF_Block = require('./CfgINF_Block.js');
let RxmSFRBX = require('./RxmSFRBX.js');
let NavTIMEUTC = require('./NavTIMEUTC.js');
let NavDOP = require('./NavDOP.js');
let CfgRST = require('./CfgRST.js');
let CfgDAT = require('./CfgDAT.js');
let NavPVT7 = require('./NavPVT7.js');
let NavSTATUS = require('./NavSTATUS.js');
let RxmSVSI_SV = require('./RxmSVSI_SV.js');
let NavSVIN = require('./NavSVIN.js');
let CfgANT = require('./CfgANT.js');
let NavSBAS = require('./NavSBAS.js');
let HnrPVT = require('./HnrPVT.js');
let RxmRTCM = require('./RxmRTCM.js');
let RxmSFRB = require('./RxmSFRB.js');
let CfgINF = require('./CfgINF.js');
let NavSVINFO = require('./NavSVINFO.js');
let MonHW = require('./MonHW.js');
let EsfSTATUS = require('./EsfSTATUS.js');
let RxmSVSI = require('./RxmSVSI.js');
let CfgSBAS = require('./CfgSBAS.js');
let CfgDGNSS = require('./CfgDGNSS.js');
let NavSBAS_SV = require('./NavSBAS_SV.js');
let MonVER = require('./MonVER.js');
let RxmRAW = require('./RxmRAW.js');
let CfgMSG = require('./CfgMSG.js');
let Ack = require('./Ack.js');
let CfgNAVX5 = require('./CfgNAVX5.js');
let MonVER_Extension = require('./MonVER_Extension.js');
let EsfRAW = require('./EsfRAW.js');
let CfgNMEA7 = require('./CfgNMEA7.js');
let RxmRAWX = require('./RxmRAWX.js');
let NavDGPS = require('./NavDGPS.js');
let AidHUI = require('./AidHUI.js');
let NavVELNED = require('./NavVELNED.js');
let TimTM2 = require('./TimTM2.js');
let MonHW6 = require('./MonHW6.js');
let EsfRAW_Block = require('./EsfRAW_Block.js');
let RxmRAWX_Meas = require('./RxmRAWX_Meas.js');
let NavATT = require('./NavATT.js');
let EsfMEAS = require('./EsfMEAS.js');
let NavSAT = require('./NavSAT.js');
let MgaGAL = require('./MgaGAL.js');
let NavDGPS_SV = require('./NavDGPS_SV.js');
let CfgUSB = require('./CfgUSB.js');
let CfgNMEA = require('./CfgNMEA.js');
let NavPVT = require('./NavPVT.js');
let NavPOSECEF = require('./NavPOSECEF.js');
let MonGNSS = require('./MonGNSS.js');
let EsfINS = require('./EsfINS.js');
let NavPOSLLH = require('./NavPOSLLH.js');
let CfgCFG = require('./CfgCFG.js');
let NavSAT_SV = require('./NavSAT_SV.js');
let UpdSOS = require('./UpdSOS.js');
let CfgGNSS = require('./CfgGNSS.js');
let Inf = require('./Inf.js');
let AidALM = require('./AidALM.js');
let RxmALM = require('./RxmALM.js');
let RxmRAW_SV = require('./RxmRAW_SV.js');
let CfgRATE = require('./CfgRATE.js');
let RxmEPH = require('./RxmEPH.js');
let NavSOL = require('./NavSOL.js');
let CfgTMODE3 = require('./CfgTMODE3.js');
let NavSVINFO_SV = require('./NavSVINFO_SV.js');
let NavVELECEF = require('./NavVELECEF.js');
let CfgNMEA6 = require('./CfgNMEA6.js');
let CfgPRT = require('./CfgPRT.js');
let UpdSOS_Ack = require('./UpdSOS_Ack.js');
let NavRELPOSNED = require('./NavRELPOSNED.js');

module.exports = {
  CfgGNSS_Block: CfgGNSS_Block,
  AidEPH: AidEPH,
  CfgNAV5: CfgNAV5,
  NavCLOCK: NavCLOCK,
  CfgHNR: CfgHNR,
  EsfSTATUS_Sens: EsfSTATUS_Sens,
  NavTIMEGPS: NavTIMEGPS,
  CfgINF_Block: CfgINF_Block,
  RxmSFRBX: RxmSFRBX,
  NavTIMEUTC: NavTIMEUTC,
  NavDOP: NavDOP,
  CfgRST: CfgRST,
  CfgDAT: CfgDAT,
  NavPVT7: NavPVT7,
  NavSTATUS: NavSTATUS,
  RxmSVSI_SV: RxmSVSI_SV,
  NavSVIN: NavSVIN,
  CfgANT: CfgANT,
  NavSBAS: NavSBAS,
  HnrPVT: HnrPVT,
  RxmRTCM: RxmRTCM,
  RxmSFRB: RxmSFRB,
  CfgINF: CfgINF,
  NavSVINFO: NavSVINFO,
  MonHW: MonHW,
  EsfSTATUS: EsfSTATUS,
  RxmSVSI: RxmSVSI,
  CfgSBAS: CfgSBAS,
  CfgDGNSS: CfgDGNSS,
  NavSBAS_SV: NavSBAS_SV,
  MonVER: MonVER,
  RxmRAW: RxmRAW,
  CfgMSG: CfgMSG,
  Ack: Ack,
  CfgNAVX5: CfgNAVX5,
  MonVER_Extension: MonVER_Extension,
  EsfRAW: EsfRAW,
  CfgNMEA7: CfgNMEA7,
  RxmRAWX: RxmRAWX,
  NavDGPS: NavDGPS,
  AidHUI: AidHUI,
  NavVELNED: NavVELNED,
  TimTM2: TimTM2,
  MonHW6: MonHW6,
  EsfRAW_Block: EsfRAW_Block,
  RxmRAWX_Meas: RxmRAWX_Meas,
  NavATT: NavATT,
  EsfMEAS: EsfMEAS,
  NavSAT: NavSAT,
  MgaGAL: MgaGAL,
  NavDGPS_SV: NavDGPS_SV,
  CfgUSB: CfgUSB,
  CfgNMEA: CfgNMEA,
  NavPVT: NavPVT,
  NavPOSECEF: NavPOSECEF,
  MonGNSS: MonGNSS,
  EsfINS: EsfINS,
  NavPOSLLH: NavPOSLLH,
  CfgCFG: CfgCFG,
  NavSAT_SV: NavSAT_SV,
  UpdSOS: UpdSOS,
  CfgGNSS: CfgGNSS,
  Inf: Inf,
  AidALM: AidALM,
  RxmALM: RxmALM,
  RxmRAW_SV: RxmRAW_SV,
  CfgRATE: CfgRATE,
  RxmEPH: RxmEPH,
  NavSOL: NavSOL,
  CfgTMODE3: CfgTMODE3,
  NavSVINFO_SV: NavSVINFO_SV,
  NavVELECEF: NavVELECEF,
  CfgNMEA6: CfgNMEA6,
  CfgPRT: CfgPRT,
  UpdSOS_Ack: UpdSOS_Ack,
  NavRELPOSNED: NavRELPOSNED,
};
