/*
 * baremetal.h
 *
 *  Created on: 18 Jun 2022
 *      Author: tmass
 */

#ifndef ARCH_BAREMETAL_ARCH_BAREMETAL_H_
#define ARCH_BAREMETAL_ARCH_BAREMETAL_H_

#pragma once

// libc dep
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <time.h>
#include <stdarg.h>

// libc++ dep
#include <iostream>
#include <string>

// linux specific
#include <unistd.h>
#include <errno.h>
#include <pthread.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
//#include <sys/ioctl.h> // does not exist on baremetal
#include <sys/select.h>
#include <time.h>

#include "timer.h"



#endif /* ARCH_BAREMETAL_ARCH_BAREMETAL_H_ */
