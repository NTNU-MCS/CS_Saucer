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

class reference_message {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.eta_d = null;
      this.eta_d_prime = null;
      this.eta_d_prime2 = null;
      this.eta_ds = null;
      this.w = null;
      this.v_s = null;
      this.v_ss = null;
    }
    else {
      if (initObj.hasOwnProperty('eta_d')) {
        this.eta_d = initObj.eta_d
      }
      else {
        this.eta_d = [];
      }
      if (initObj.hasOwnProperty('eta_d_prime')) {
        this.eta_d_prime = initObj.eta_d_prime
      }
      else {
        this.eta_d_prime = [];
      }
      if (initObj.hasOwnProperty('eta_d_prime2')) {
        this.eta_d_prime2 = initObj.eta_d_prime2
      }
      else {
        this.eta_d_prime2 = [];
      }
      if (initObj.hasOwnProperty('eta_ds')) {
        this.eta_ds = initObj.eta_ds
      }
      else {
        this.eta_ds = [];
      }
      if (initObj.hasOwnProperty('w')) {
        this.w = initObj.w
      }
      else {
        this.w = 0.0;
      }
      if (initObj.hasOwnProperty('v_s')) {
        this.v_s = initObj.v_s
      }
      else {
        this.v_s = 0.0;
      }
      if (initObj.hasOwnProperty('v_ss')) {
        this.v_ss = initObj.v_ss
      }
      else {
        this.v_ss = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type reference_message
    // Serialize message field [eta_d]
    bufferOffset = _arraySerializer.float64(obj.eta_d, buffer, bufferOffset, null);
    // Serialize message field [eta_d_prime]
    bufferOffset = _arraySerializer.float64(obj.eta_d_prime, buffer, bufferOffset, null);
    // Serialize message field [eta_d_prime2]
    bufferOffset = _arraySerializer.float64(obj.eta_d_prime2, buffer, bufferOffset, null);
    // Serialize message field [eta_ds]
    bufferOffset = _arraySerializer.float64(obj.eta_ds, buffer, bufferOffset, null);
    // Serialize message field [w]
    bufferOffset = _serializer.float64(obj.w, buffer, bufferOffset);
    // Serialize message field [v_s]
    bufferOffset = _serializer.float64(obj.v_s, buffer, bufferOffset);
    // Serialize message field [v_ss]
    bufferOffset = _serializer.float64(obj.v_ss, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type reference_message
    let len;
    let data = new reference_message(null);
    // Deserialize message field [eta_d]
    data.eta_d = _arrayDeserializer.float64(buffer, bufferOffset, null)
    // Deserialize message field [eta_d_prime]
    data.eta_d_prime = _arrayDeserializer.float64(buffer, bufferOffset, null)
    // Deserialize message field [eta_d_prime2]
    data.eta_d_prime2 = _arrayDeserializer.float64(buffer, bufferOffset, null)
    // Deserialize message field [eta_ds]
    data.eta_ds = _arrayDeserializer.float64(buffer, bufferOffset, null)
    // Deserialize message field [w]
    data.w = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [v_s]
    data.v_s = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [v_ss]
    data.v_ss = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 8 * object.eta_d.length;
    length += 8 * object.eta_d_prime.length;
    length += 8 * object.eta_d_prime2.length;
    length += 8 * object.eta_ds.length;
    return length + 40;
  }

  static datatype() {
    // Returns string type for a message object
    return 'messages/reference_message';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '32123cd43ccb33fbbded09fe4a9ec786';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64[] eta_d
    float64[] eta_d_prime
    float64[] eta_d_prime2
    float64[] eta_ds
    float64 w
    float64 v_s
    float64 v_ss
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new reference_message(null);
    if (msg.eta_d !== undefined) {
      resolved.eta_d = msg.eta_d;
    }
    else {
      resolved.eta_d = []
    }

    if (msg.eta_d_prime !== undefined) {
      resolved.eta_d_prime = msg.eta_d_prime;
    }
    else {
      resolved.eta_d_prime = []
    }

    if (msg.eta_d_prime2 !== undefined) {
      resolved.eta_d_prime2 = msg.eta_d_prime2;
    }
    else {
      resolved.eta_d_prime2 = []
    }

    if (msg.eta_ds !== undefined) {
      resolved.eta_ds = msg.eta_ds;
    }
    else {
      resolved.eta_ds = []
    }

    if (msg.w !== undefined) {
      resolved.w = msg.w;
    }
    else {
      resolved.w = 0.0
    }

    if (msg.v_s !== undefined) {
      resolved.v_s = msg.v_s;
    }
    else {
      resolved.v_s = 0.0
    }

    if (msg.v_ss !== undefined) {
      resolved.v_ss = msg.v_ss;
    }
    else {
      resolved.v_ss = 0.0
    }

    return resolved;
    }
};

module.exports = reference_message;
