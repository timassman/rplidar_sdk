/*
 *  RPLIDAR SDK
 *
 *  Copyright (c) 2009 - 2014 RoboPeak Team
 *  http://www.robopeak.com
 *  Copyright (c) 2014 - 2020 Shanghai Slamtec Co., Ltd.
 *  http://www.slamtec.com
 *
 */
/*
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include "sdkcommon.h"
#include "net_serial.h"

namespace rp{ namespace arch{ namespace net{

raw_serial::raw_serial()
    : rp::hal::serial_rxtx()
    , _baudrate(0)
    , _flags(0)
{
    _init();
}

raw_serial::~raw_serial()
{
    close();
}

bool raw_serial::open()
{
    return open(_portName, _baudrate, _flags);
}

bool raw_serial::bind(const char * portname, _u32 baudrate, _u32 flags)
{   
    strncpy(_portName, portname, sizeof(_portName));
    _baudrate = baudrate;
    _flags    = flags;
    return true;
}

bool raw_serial::open(const char * portname, _u32 baudrate, _u32 flags)
{
    return true;
}

void raw_serial::close()
{
}

int raw_serial::senddata(const unsigned char * data, size_t size)
{
	return 0;
}

int raw_serial::recvdata(unsigned char * data, size_t size)
{
	return 0;
}

void raw_serial::flush( _u32 flags)
{
}

int raw_serial::waitforsent(_u32 timeout, size_t * returned_size)
{
	return 0;
}

int raw_serial::waitforrecv(_u32 timeout, size_t * returned_size)
{
	return 0;
}

int raw_serial::waitfordata(size_t data_count, _u32 timeout, size_t * returned_size)
{
	return 0;
}

size_t raw_serial::rxqueue_count()
{
	return 0;
}

void raw_serial::setDTR()
{
}

void raw_serial::clearDTR()
{
}


void raw_serial::_init()
{
}

}}} //end rp::arch::net


//begin rp::hal
namespace rp{ namespace hal{

serial_rxtx * serial_rxtx::CreateRxTx()
{
    return new rp::arch::net::raw_serial();
}

void  serial_rxtx::ReleaseRxTx( serial_rxtx * rxtx)
{
    delete rxtx;
}


}} //end rp::hal
