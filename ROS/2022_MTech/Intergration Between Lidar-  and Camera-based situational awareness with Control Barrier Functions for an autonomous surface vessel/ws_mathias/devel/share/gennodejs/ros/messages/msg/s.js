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

class s {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.s = null;
      this.s_dot = null;
    }
    else {
      if (initObj.hasOwnProperty('s')) {
        this.s = initObj.s
      }
      else {
        this.s = [];
      }
      if (initObj.hasOwnProperty('s_dot')) {
        this.s_dot = initObj.s_dot
      }
      else {
        this.s_dot = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type s
    // Serialize message field [s]
    bufferOffset = _arraySerializer.float64(obj.s, buffer, bufferOffset, null);
    // Serialize message field [s_dot]
    bufferOffset = _arraySerializer.float64(obj.s_dot, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type s
    let len;
    let data = new s(null);
    // Deserialize message field [s]
    data.s = _arrayDeserializer.float64(buffer, bufferOffset, null)
    // Deserialize message field [s_dot]
    data.s_dot = _arrayDeserializer.float64(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 8 * object.s.length;
    length += 8 * object.s_dot.length;
    return length + 8;
  }

  static datatype() {
    // Returns string type for a message object
    return 'messages/s';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '14fb056663501f0195cd852f090d3a8f';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64[] s
    float64[] s_dot
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new s(null);
    if (msg.s !== undefined) {
      resolved.s = msg.s;
    }
    else {
      resolved.s = []
    }

    if (msg.s_dot !== undefined) {
      resolved.s_dot = msg.s_dot;
    }
    else {
      resolved.s_dot = []
    }

    return resolved;
    }
};

module.exports = s;
