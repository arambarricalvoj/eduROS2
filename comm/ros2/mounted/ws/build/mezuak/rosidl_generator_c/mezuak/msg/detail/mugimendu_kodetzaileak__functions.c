// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from mezuak:msg/MugimenduKodetzaileak.idl
// generated code does not contain a copyright notice
#include "mezuak/msg/detail/mugimendu_kodetzaileak__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
mezuak__msg__MugimenduKodetzaileak__init(mezuak__msg__MugimenduKodetzaileak * msg)
{
  if (!msg) {
    return false;
  }
  // graduak
  return true;
}

void
mezuak__msg__MugimenduKodetzaileak__fini(mezuak__msg__MugimenduKodetzaileak * msg)
{
  if (!msg) {
    return;
  }
  // graduak
}

bool
mezuak__msg__MugimenduKodetzaileak__are_equal(const mezuak__msg__MugimenduKodetzaileak * lhs, const mezuak__msg__MugimenduKodetzaileak * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // graduak
  for (size_t i = 0; i < 2; ++i) {
    if (lhs->graduak[i] != rhs->graduak[i]) {
      return false;
    }
  }
  return true;
}

bool
mezuak__msg__MugimenduKodetzaileak__copy(
  const mezuak__msg__MugimenduKodetzaileak * input,
  mezuak__msg__MugimenduKodetzaileak * output)
{
  if (!input || !output) {
    return false;
  }
  // graduak
  for (size_t i = 0; i < 2; ++i) {
    output->graduak[i] = input->graduak[i];
  }
  return true;
}

mezuak__msg__MugimenduKodetzaileak *
mezuak__msg__MugimenduKodetzaileak__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mezuak__msg__MugimenduKodetzaileak * msg = (mezuak__msg__MugimenduKodetzaileak *)allocator.allocate(sizeof(mezuak__msg__MugimenduKodetzaileak), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mezuak__msg__MugimenduKodetzaileak));
  bool success = mezuak__msg__MugimenduKodetzaileak__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mezuak__msg__MugimenduKodetzaileak__destroy(mezuak__msg__MugimenduKodetzaileak * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mezuak__msg__MugimenduKodetzaileak__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mezuak__msg__MugimenduKodetzaileak__Sequence__init(mezuak__msg__MugimenduKodetzaileak__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mezuak__msg__MugimenduKodetzaileak * data = NULL;

  if (size) {
    data = (mezuak__msg__MugimenduKodetzaileak *)allocator.zero_allocate(size, sizeof(mezuak__msg__MugimenduKodetzaileak), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mezuak__msg__MugimenduKodetzaileak__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mezuak__msg__MugimenduKodetzaileak__fini(&data[i - 1]);
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
mezuak__msg__MugimenduKodetzaileak__Sequence__fini(mezuak__msg__MugimenduKodetzaileak__Sequence * array)
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
      mezuak__msg__MugimenduKodetzaileak__fini(&array->data[i]);
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

mezuak__msg__MugimenduKodetzaileak__Sequence *
mezuak__msg__MugimenduKodetzaileak__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mezuak__msg__MugimenduKodetzaileak__Sequence * array = (mezuak__msg__MugimenduKodetzaileak__Sequence *)allocator.allocate(sizeof(mezuak__msg__MugimenduKodetzaileak__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mezuak__msg__MugimenduKodetzaileak__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mezuak__msg__MugimenduKodetzaileak__Sequence__destroy(mezuak__msg__MugimenduKodetzaileak__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mezuak__msg__MugimenduKodetzaileak__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mezuak__msg__MugimenduKodetzaileak__Sequence__are_equal(const mezuak__msg__MugimenduKodetzaileak__Sequence * lhs, const mezuak__msg__MugimenduKodetzaileak__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mezuak__msg__MugimenduKodetzaileak__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mezuak__msg__MugimenduKodetzaileak__Sequence__copy(
  const mezuak__msg__MugimenduKodetzaileak__Sequence * input,
  mezuak__msg__MugimenduKodetzaileak__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mezuak__msg__MugimenduKodetzaileak);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mezuak__msg__MugimenduKodetzaileak * data =
      (mezuak__msg__MugimenduKodetzaileak *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mezuak__msg__MugimenduKodetzaileak__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mezuak__msg__MugimenduKodetzaileak__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mezuak__msg__MugimenduKodetzaileak__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
