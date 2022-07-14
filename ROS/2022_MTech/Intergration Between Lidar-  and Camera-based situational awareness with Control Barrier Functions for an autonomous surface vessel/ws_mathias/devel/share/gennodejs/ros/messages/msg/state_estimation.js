// Auto-generated. Do not edit!

// (in-package messages.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class state_estimation {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.eta_hat = null;
      this.nu_hat = null;
      this.bias_hat = null;
    }
    else {
      if (initObj.hasOwnProperty('eta_hat')) {
        this.eta_hat = initObj.eta_hat
      }
      else {
        this.eta_hat = [];
      }
      if (initObj.hasOwnProperty('nu_hat')) {
        this.nu_hat = initObj.nu_hat
      }
      else {
        this.nu_hat = [];
      }
      if (initObj.hasOwnProperty('bias_hat')) {
        this.bias_hat = initObj.bias_hat
      }
      else {
        this.bias_hat = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type state_estimation
    // Serialize message field [eta_hat]
    bufferOffset = _arraySerializer.float64(obj.eta_hat, buffer, bufferOffset, null);
    // Serialize message field [nu_hat]
    bufferOffset = _arraySerializer.float64(obj.nu_hat, buffer, bufferOffset, null);
    // Serialize message field [bias_hat]
    bufferOffset = _arraySerializer.float64(obj.bias_hat, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type state_estimation
    let len;
    let data = new state_estimation(null);
    // Deserialize message field [eta_hat]
    data.eta_hat = _arrayDeserializer.float64(buffer, bufferOffset, null)
    // Deserialize message field [nu_hat]
    data.nu_hat = _arrayDeserializer.float64(buffer, bufferOffset, null)
    // Deserialize message field [bias_hat]
    data.bias_hat = _arrayDeserializer.float64(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 8 * object.eta_hat.length;
    length += 8 * object.nu_hat.length;
    length += 8 * object.bias_hat.length;
    return length + 12;
  }

  static datatype() {
    // Returns string type for a message object
    return 'messages/state_estimation';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '8f1bb4322eba02c2ff0b75462df79905';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64[] eta_hat
    float64[] nu_hat
    float64[] bias_hat
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new state_estimation(null);
    if (msg.eta_hat !== undefined) {
      resolved.eta_hat = msg.eta_hat;
    }
    else {
      resolved.eta_hat = []
    }

    if (msg.nu_hat !== undefined) {
      resolved.nu_hat = msg.nu_hat;
    }
    else {
      resolved.nu_hat = []
    }

    if (msg.bias_hat !== undefined) {
      resolved.bias_hat = msg.bias_hat;
    }
    else {
      resolved.bias_hat = []
    }

    return resolved;
    }
};

module.exports = state_estimation;
