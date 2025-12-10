// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from mezuak:msg/IkasDatuak.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "mezuak/msg/detail/ikas_datuak__struct.h"
#include "mezuak/msg/detail/ikas_datuak__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool mezuak__msg__ikas_datuak__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[35];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("mezuak.msg._ikas_datuak.IkasDatuak", full_classname_dest, 34) == 0);
  }
  mezuak__msg__IkasDatuak * ros_message = _ros_message;
  {  // pos_izq
    PyObject * field = PyObject_GetAttrString(_pymsg, "pos_izq");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->pos_izq = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // pos_der
    PyObject * field = PyObject_GetAttrString(_pymsg, "pos_der");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->pos_der = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // vel_izq
    PyObject * field = PyObject_GetAttrString(_pymsg, "vel_izq");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->vel_izq = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // vel_der
    PyObject * field = PyObject_GetAttrString(_pymsg, "vel_der");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->vel_der = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // yaw
    PyObject * field = PyObject_GetAttrString(_pymsg, "yaw");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->yaw = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // error_traj
    PyObject * field = PyObject_GetAttrString(_pymsg, "error_traj");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->error_traj = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // delta_v
    PyObject * field = PyObject_GetAttrString(_pymsg, "delta_v");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->delta_v = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // dist_restante
    PyObject * field = PyObject_GetAttrString(_pymsg, "dist_restante");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->dist_restante = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // reward
    PyObject * field = PyObject_GetAttrString(_pymsg, "reward");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->reward = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // done
    PyObject * field = PyObject_GetAttrString(_pymsg, "done");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->done = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * mezuak__msg__ikas_datuak__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of IkasDatuak */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("mezuak.msg._ikas_datuak");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "IkasDatuak");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  mezuak__msg__IkasDatuak * ros_message = (mezuak__msg__IkasDatuak *)raw_ros_message;
  {  // pos_izq
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->pos_izq);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pos_izq", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pos_der
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->pos_der);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pos_der", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // vel_izq
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->vel_izq);
    {
      int rc = PyObject_SetAttrString(_pymessage, "vel_izq", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // vel_der
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->vel_der);
    {
      int rc = PyObject_SetAttrString(_pymessage, "vel_der", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // yaw
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->yaw);
    {
      int rc = PyObject_SetAttrString(_pymessage, "yaw", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // error_traj
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->error_traj);
    {
      int rc = PyObject_SetAttrString(_pymessage, "error_traj", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // delta_v
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->delta_v);
    {
      int rc = PyObject_SetAttrString(_pymessage, "delta_v", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // dist_restante
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->dist_restante);
    {
      int rc = PyObject_SetAttrString(_pymessage, "dist_restante", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // reward
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->reward);
    {
      int rc = PyObject_SetAttrString(_pymessage, "reward", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // done
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->done ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "done", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
