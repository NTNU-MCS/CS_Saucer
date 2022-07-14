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

class observer_message {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.eta = null;
      this.nu = null;
      this.bias = null;
    }
    else {
      if (initObj.hasOwnProperty('eta')) {
        this.eta = initObj.eta
      }
      else {
        this.eta = [];
      }
      if (initObj.hasOwnProperty('nu')) {
        this.nu = initObj.nu
      }
      else {
        this.nu = [];
      }
      if (initObj.hasOwnProperty('bias')) {
        this.bias = initObj.bias
      }
      else {
        this.bias = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type observer_message
    // Serialize message field [eta]
    bufferOffset = _arraySerializer.float64(obj.eta, buffer, bufferOffset, null);
    // Serialize message field [nu]
    bufferOffset = _arraySerializer.float64(obj.nu, buffer, bufferOffset, null);
    // Serialize message field [bias]
    bufferOffset = _arraySerializer.float64(obj.bias, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type observer_message
    let len;
    let data = new observer_message(null);
    // Deserialize message field [eta]
    data.eta = _arrayDeserializer.float64(buffer, bufferOffset, null)
    // Deserialize message field [nu]
    data.nu = _arrayDeserializer.float64(buffer, bufferOffset, null)
    // Deserialize message field [bias]
    data.bias = _arrayDeserializer.float64(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 8 * object.eta.length;
    length += 8 * object.nu.length;
    length += 8 * object.bias.length;
    return length + 12;
  }

  static datatype() {
    // Returns string type for a message object
    return 'messages/observer_message';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '7f3202088d21e8801c58a7a4f2fe213a';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64[] eta
    float64[] nu
    float64[] bias
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new observer_message(null);
    if (msg.eta !== undefined) {
      resolved.eta = msg.eta;
    }
    else {
      resolved.eta = []
    }

    if (msg.nu !== undefined) {
      resolved.nu = msg.nu;
    }
    else {
      resolved.nu = []
    }

    if (msg.bias !== undefined) {
      resolved.bias = msg.bias;
    }
    else {
      resolved.bias = []
    }

    return resolved;
    }
};

module.exports = observer_message;
