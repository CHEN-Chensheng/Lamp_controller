
"use strict";

let SetTorqueLimit = require('./SetTorqueLimit.js')
let StartController = require('./StartController.js')
let SetComplianceSlope = require('./SetComplianceSlope.js')
let TorqueEnable = require('./TorqueEnable.js')
let SetCompliancePunch = require('./SetCompliancePunch.js')
let StopController = require('./StopController.js')
let RestartController = require('./RestartController.js')
let SetSpeed = require('./SetSpeed.js')
let SetComplianceMargin = require('./SetComplianceMargin.js')

module.exports = {
  SetTorqueLimit: SetTorqueLimit,
  StartController: StartController,
  SetComplianceSlope: SetComplianceSlope,
  TorqueEnable: TorqueEnable,
  SetCompliancePunch: SetCompliancePunch,
  StopController: StopController,
  RestartController: RestartController,
  SetSpeed: SetSpeed,
  SetComplianceMargin: SetComplianceMargin,
};
