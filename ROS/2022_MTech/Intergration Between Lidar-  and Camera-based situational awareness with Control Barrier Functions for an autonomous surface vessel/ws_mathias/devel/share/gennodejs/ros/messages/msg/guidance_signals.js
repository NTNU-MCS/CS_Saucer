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

class guidance_signals {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.eta_d = null;
      this.pd_s1 = null;
      this.pd_s2 = null;
      this.pd_ss1 = null;
      this.pd_ss2 = null;
      this.psi_d_dot = null;
      this.psi_d_ddot = null;
    }
    else {
      if (initObj.hasOwnProperty('eta_d')) {
        this.eta_d = initObj.eta_d
      }
      else {
        this.eta_d = [];
      }
      if (initObj.hasOwnProperty('pd_s1')) {
        this.pd_s1 = initObj.pd_s1
      }
      else {
        this.pd_s1 = [];
      }
      if (initObj.hasOwnProperty('pd_s2')) {
        this.pd_s2 = initObj.pd_s2
      }
      else {
        this.pd_s2 = [];
      }
      if (initObj.hasOwnProperty('pd_ss1')) {
        this.pd_ss1 = initObj.pd_ss1
      }
      else {
        this.pd_ss1 = [];
      }
      if (initObj.hasOwnProperty('pd_ss2')) {
        this.pd_ss2 = initObj.pd_ss2
      }
      else {
        this.pd_ss2 = [];
      }
      if (initObj.hasOwnProperty('psi_d_dot')) {
        this.psi_d_dot = initObj.psi_d_dot
      }
      else {
        this.psi_d_dot = 0.0;
      }
      if (initObj.hasOwnProperty('psi_d_ddot')) {
        this.psi_d_ddot = initObj.psi_d_ddot
      }
      else {
        this.psi_d_ddot = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type guidance_signals
    // Serialize message field [eta_d]
    bufferOffset = _arraySerializer.float64(obj.eta_d, buffer, bufferOffset, null);
    // Serialize message field [pd_s1]
    bufferOffset = _arraySerializer.float64(obj.pd_s1, buffer, bufferOffset, null);
    // Serialize message field [pd_s2]
    bufferOffset = _arraySerializer.float64(obj.pd_s2, buffer, bufferOffset, null);
    // Serialize message field [pd_ss1]
    bufferOffset = _arraySerializer.float64(obj.pd_ss1, buffer, bufferOffset, null);
    // Serialize message field [pd_ss2]
    bufferOffset = _arraySerializer.float64(obj.pd_ss2, buffer, bufferOffset, null);
    // Serialize message field [psi_d_dot]
    bufferOffset = _serializer.float64(obj.psi_d_dot, buffer, bufferOffset);
    // Serialize message field [psi_d_ddot]
    bufferOffset = _serializer.float64(obj.psi_d_ddot, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type guidance_signals
    let len;
    let data = new guidance_signals(null);
    // Deserialize message field [eta_d]
    data.eta_d = _arrayDeserializer.float64(buffer, bufferOffset, null)
    // Deserialize message field [pd_s1]
    data.pd_s1 = _arrayDeserializer.float64(buffer, bufferOffset, null)
    // Deserialize message field [pd_s2]
    data.pd_s2 = _arrayDeserializer.float64(buffer, bufferOffset, null)
    // Deserialize message field [pd_ss1]
    data.pd_ss1 = _arrayDeserializer.float64(buffer, bufferOffset, null)
    // Deserialize message field [pd_ss2]
    data.pd_ss2 = _arrayDeserializer.float64(buffer, bufferOffset, null)
    // Deserialize message field [psi_d_dot]
    data.psi_d_dot = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [psi_d_ddot]
    data.psi_d_ddot = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 8 * object.eta_d.length;
    length += 8 * object.pd_s1.length;
    length += 8 * object.pd_s2.length;
    length += 8 * object.pd_ss1.length;
    length += 8 * object.pd_ss2.length;
    return length + 36;
  }

  static datatype() {
    // Returns string type for a message object
    return 'messages/guidance_signals';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'fd30d3a050e6c9293f8dcca19a9c94ca';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64[] eta_d
    float64[] pd_s1
    float64[] pd_s2
    float64[] pd_ss1
    float64[] pd_ss2
    float64 psi_d_dot
    float64 psi_d_ddot
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new guidance_signals(null);
    if (msg.eta_d !== undefined) {
      resolved.eta_d = msg.eta_d;
    }
    else {
      resolved.eta_d = []
    }

    if (msg.pd_s1 !== undefined) {
      resolved.pd_s1 = msg.pd_s1;
    }
    else {
      resolved.pd_s1 = []
    }

    if (msg.pd_s2 !== undefined) {
      resolved.pd_s2 = msg.pd_s2;
    }
    else {
      resolved.pd_s2 = []
    }

    if (msg.pd_ss1 !== undefined) {
      resolved.pd_ss1 = msg.pd_ss1;
    }
    else {
      resolved.pd_ss1 = []
    }

    if (msg.pd_ss2 !== undefined) {
      resolved.pd_ss2 = msg.pd_ss2;
    }
    else {
      resolved.pd_ss2 = []
    }

    if (msg.psi_d_dot !== undefined) {
      resolved.psi_d_dot = msg.psi_d_dot;
    }
    else {
      resolved.psi_d_dot = 0.0
    }

    if (msg.psi_d_ddot !== undefined) {
      resolved.psi_d_ddot = msg.psi_d_ddot;
    }
    else {
      resolved.psi_d_ddot = 0.0
    }

    return resolved;
    }
};

module.exports = guidance_signals;
