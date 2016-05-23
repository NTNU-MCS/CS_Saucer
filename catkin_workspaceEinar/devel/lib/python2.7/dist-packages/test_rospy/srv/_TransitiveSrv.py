# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from test_rospy/TransitiveSrvRequest.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import test_rospy.msg
import test_rosmaster.msg

class TransitiveSrvRequest(genpy.Message):
  _md5sum = "c9627b8665f2e2514f3d19406d2ed17d"
  _type = "test_rospy/TransitiveSrvRequest"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """test_rospy/TransitiveMsg1 msg

================================================================================
MSG: test_rospy/TransitiveMsg1
TransitiveMsg2 msg2


================================================================================
MSG: test_rospy/TransitiveMsg2
test_rosmaster/Composite data

================================================================================
MSG: test_rosmaster/Composite
# composite message. required for testing import calculation in generators
CompositeA a
CompositeB b

================================================================================
MSG: test_rosmaster/CompositeA
# This represents an orientation in free space in quaternion form.

float64 x
float64 y
float64 z
float64 w

================================================================================
MSG: test_rosmaster/CompositeB
# copy of geometry_msgs/Point for testing
float64 x
float64 y
float64 z

"""
  __slots__ = ['msg']
  _slot_types = ['test_rospy/TransitiveMsg1']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       msg

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(TransitiveSrvRequest, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.msg is None:
        self.msg = test_rospy.msg.TransitiveMsg1()
    else:
      self.msg = test_rospy.msg.TransitiveMsg1()

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_struct_7d.pack(_x.msg.msg2.data.a.x, _x.msg.msg2.data.a.y, _x.msg.msg2.data.a.z, _x.msg.msg2.data.a.w, _x.msg.msg2.data.b.x, _x.msg.msg2.data.b.y, _x.msg.msg2.data.b.z))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(_x))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(_x))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      if self.msg is None:
        self.msg = test_rospy.msg.TransitiveMsg1()
      end = 0
      _x = self
      start = end
      end += 56
      (_x.msg.msg2.data.a.x, _x.msg.msg2.data.a.y, _x.msg.msg2.data.a.z, _x.msg.msg2.data.a.w, _x.msg.msg2.data.b.x, _x.msg.msg2.data.b.y, _x.msg.msg2.data.b.z,) = _struct_7d.unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_struct_7d.pack(_x.msg.msg2.data.a.x, _x.msg.msg2.data.a.y, _x.msg.msg2.data.a.z, _x.msg.msg2.data.a.w, _x.msg.msg2.data.b.x, _x.msg.msg2.data.b.y, _x.msg.msg2.data.b.z))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(_x))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(_x))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      if self.msg is None:
        self.msg = test_rospy.msg.TransitiveMsg1()
      end = 0
      _x = self
      start = end
      end += 56
      (_x.msg.msg2.data.a.x, _x.msg.msg2.data.a.y, _x.msg.msg2.data.a.z, _x.msg.msg2.data.a.w, _x.msg.msg2.data.b.x, _x.msg.msg2.data.b.y, _x.msg.msg2.data.b.z,) = _struct_7d.unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
_struct_7d = struct.Struct("<7d")
# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from test_rospy/TransitiveSrvResponse.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class TransitiveSrvResponse(genpy.Message):
  _md5sum = "5c9fb1a886e81e3162a5c87bf55c072b"
  _type = "test_rospy/TransitiveSrvResponse"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """int32 a



"""
  __slots__ = ['a']
  _slot_types = ['int32']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       a

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(TransitiveSrvResponse, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.a is None:
        self.a = 0
    else:
      self.a = 0

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      buff.write(_struct_i.pack(self.a))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(_x))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(_x))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      start = end
      end += 4
      (self.a,) = _struct_i.unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      buff.write(_struct_i.pack(self.a))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(_x))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(_x))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      end = 0
      start = end
      end += 4
      (self.a,) = _struct_i.unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
_struct_i = struct.Struct("<i")
class TransitiveSrv(object):
  _type          = 'test_rospy/TransitiveSrv'
  _md5sum = '8b7918ee2b81eaf825f4c70de011f6fa'
  _request_class  = TransitiveSrvRequest
  _response_class = TransitiveSrvResponse