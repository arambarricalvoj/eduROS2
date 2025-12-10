// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from mezuak:msg/IkasDatuak.idl
// generated code does not contain a copyright notice
#include "mezuak/msg/detail/ikas_datuak__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
mezuak__msg__IkasDatuak__init(mezuak__msg__IkasDatuak * msg)
{
  if (!msg) {
    return false;
  }
  // pos_izq
  // pos_der
  // vel_izq
  // vel_der
  // yaw
  // error_traj
  // delta_v
  // dist_restante
  // reward
  // done
  return true;
}

void
mezuak__msg__IkasDatuak__fini(mezuak__msg__IkasDatuak * msg)
{
  if (!msg) {
    return;
  }
  // pos_izq
  // pos_der
  // vel_izq
  // vel_der
  // yaw
  // error_traj
  // delta_v
  // dist_restante
  // reward
  // done
}

bool
mezuak__msg__IkasDatuak__are_equal(const mezuak__msg__IkasDatuak * lhs, const mezuak__msg__IkasDatuak * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // pos_izq
  if (lhs->pos_izq != rhs->pos_izq) {
    return false;
  }
  // pos_der
  if (lhs->pos_der != rhs->pos_der) {
    return false;
  }
  // vel_izq
  if (lhs->vel_izq != rhs->vel_izq) {
    return false;
  }
  // vel_der
  if (lhs->vel_der != rhs->vel_der) {
    return false;
  }
  // yaw
  if (lhs->yaw != rhs->yaw) {
    return false;
  }
  // error_traj
  if (lhs->error_traj != rhs->error_traj) {
    return false;
  }
  // delta_v
  if (lhs->delta_v != rhs->delta_v) {
    return false;
  }
  // dist_restante
  if (lhs->dist_restante != rhs->dist_restante) {
    return false;
  }
  // reward
  if (lhs->reward != rhs->reward) {
    return false;
  }
  // done
  if (lhs->done != rhs->done) {
    return false;
  }
  return true;
}

bool
mezuak__msg__IkasDatuak__copy(
  const mezuak__msg__IkasDatuak * input,
  mezuak__msg__IkasDatuak * output)
{
  if (!input || !output) {
    return false;
  }
  // pos_izq
  output->pos_izq = input->pos_izq;
  // pos_der
  output->pos_der = input->pos_der;
  // vel_izq
  output->vel_izq = input->vel_izq;
  // vel_der
  output->vel_der = input->vel_der;
  // yaw
  output->yaw = input->yaw;
  // error_traj
  output->error_traj = input->error_traj;
  // delta_v
  output->delta_v = input->delta_v;
  // dist_restante
  output->dist_restante = input->dist_restante;
  // reward
  output->reward = input->reward;
  // done
  output->done = input->done;
  return true;
}

mezuak__msg__IkasDatuak *
mezuak__msg__IkasDatuak__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mezuak__msg__IkasDatuak * msg = (mezuak__msg__IkasDatuak *)allocator.allocate(sizeof(mezuak__msg__IkasDatuak), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mezuak__msg__IkasDatuak));
  bool success = mezuak__msg__IkasDatuak__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mezuak__msg__IkasDatuak__destroy(mezuak__msg__IkasDatuak * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mezuak__msg__IkasDatuak__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mezuak__msg__IkasDatuak__Sequence__init(mezuak__msg__IkasDatuak__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mezuak__msg__IkasDatuak * data = NULL;

  if (size) {
    data = (mezuak__msg__IkasDatuak *)allocator.zero_allocate(size, sizeof(mezuak__msg__IkasDatuak), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mezuak__msg__IkasDatuak__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mezuak__msg__IkasDatuak__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
mezuak__msg__IkasDatuak__Sequence__fini(mezuak__msg__IkasDatuak__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      mezuak__msg__IkasDatuak__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

mezuak__msg__IkasDatuak__Sequence *
mezuak__msg__IkasDatuak__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mezuak__msg__IkasDatuak__Sequence * array = (mezuak__msg__IkasDatuak__Sequence *)allocator.allocate(sizeof(mezuak__msg__IkasDatuak__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mezuak__msg__IkasDatuak__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mezuak__msg__IkasDatuak__Sequence__destroy(mezuak__msg__IkasDatuak__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mezuak__msg__IkasDatuak__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mezuak__msg__IkasDatuak__Sequence__are_equal(const mezuak__msg__IkasDatuak__Sequence * lhs, const mezuak__msg__IkasDatuak__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mezuak__msg__IkasDatuak__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mezuak__msg__IkasDatuak__Sequence__copy(
  const mezuak__msg__IkasDatuak__Sequence * input,
  mezuak__msg__IkasDatuak__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mezuak__msg__IkasDatuak);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mezuak__msg__IkasDatuak * data =
      (mezuak__msg__IkasDatuak *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mezuak__msg__IkasDatuak__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mezuak__msg__IkasDatuak__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mezuak__msg__IkasDatuak__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
