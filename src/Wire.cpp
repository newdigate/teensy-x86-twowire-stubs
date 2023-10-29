/*
  TwoWire.cpp - TWI/I2C library for Wiring & Arduino
  Copyright (c) 2006 Nicholas Zambetti.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 
  Modified 2012 by Todd Krein (todd@krein.org) to implement repeated starts
*/

#include <Arduino.h>

#include "Wire.h"

extern "C" {
  #include <stdlib.h>
  #include <string.h>
  #include <inttypes.h>
}

// Initialize Class Variables //////////////////////////////////////////////////

uint8_t TwoWire::rxBuffer[BUFFER_LENGTH];
uint8_t TwoWire::rxBufferIndex = 0;
uint8_t TwoWire::rxBufferLength = 0;

uint8_t TwoWire::txAddress = 0;
uint8_t TwoWire::txBuffer[BUFFER_LENGTH];
uint8_t TwoWire::txBufferIndex = 0;
uint8_t TwoWire::txBufferLength = 0;

uint8_t TwoWire::transmitting = 0;
void (*TwoWire::user_onRequest)(void);
void (*TwoWire::user_onReceive)(int);

// Constructors ////////////////////////////////////////////////////////////////

TwoWire::TwoWire()
{
}

// Public Methods //////////////////////////////////////////////////////////////

void TwoWire::begin(void)
{
  rxBufferIndex = 0;
  rxBufferLength = 0;

  txBufferIndex = 0;
  txBufferLength = 0;
}

void TwoWire::begin(uint8_t address)
{
  begin();
}

void TwoWire::end()
{
}

void TwoWire::setClock(uint32_t frequency)
{
}

void TwoWire::setSDA(uint8_t pin)
{
}

void TwoWire::setSCL(uint8_t pin)
{
}

uint8_t TwoWire::requestFrom(uint8_t address, uint8_t quantity, uint8_t sendStop)
{
  return 0;
}

uint8_t TwoWire::requestFrom(uint8_t addr, uint8_t qty, uint32_t iaddr, uint8_t n, uint8_t stop)
{
    return 0;
}

void TwoWire::beginTransmission(uint8_t address)
{
 
}

//
//	Originally, 'endTransmission' was an f(void) function.
//	It has been modified to take one parameter indicating
//	whether or not a STOP should be performed on the bus.
//	Calling endTransmission(false) allows a sketch to 
//	perform a repeated start. 
//
//	WARNING: Nothing in the library keeps track of whether
//	the bus tenure has been properly ended with a STOP. It
//	is very possible to leave the bus in a hung state if
//	no call to endTransmission(true) is made. Some I2C
//	devices will behave oddly if they do not see a STOP.
//
uint8_t TwoWire::endTransmission(uint8_t sendStop)
{
  return 0;
}

// must be called in:
// slave tx event callback
// or after beginTransmission(address)
size_t TwoWire::write(uint8_t data)
{
  return 1;
}

// must be called in:
// slave tx event callback
// or after beginTransmission(address)
size_t TwoWire::write(const uint8_t *data, size_t quantity)
{
  return quantity;
}

// must be called in:
// slave rx event callback
// or after requestFrom(address, numBytes)
int TwoWire::available(void)
{
  return rxBufferLength - rxBufferIndex;
}

// must be called in:
// slave rx event callback
// or after requestFrom(address, numBytes)
int TwoWire::read(void)
{
  return -1;
}

// must be called in:
// slave rx event callback
// or after requestFrom(address, numBytes)
int TwoWire::peek(void)
{
  int value = -1;
  return value;
}

void TwoWire::flush(void)
{
  // XXX: to be implemented.
}

// behind the scenes function that is called when data is received
void TwoWire::onReceiveService(uint8_t* inBytes, int numBytes)
{
}

// behind the scenes function that is called when data is requested
void TwoWire::onRequestService(void)
{
}

// sets function called on slave write
void TwoWire::onReceive( void (*function)(int) )
{
}

// sets function called on slave read
void TwoWire::onRequest( void (*function)(void) )
{
}

// Preinstantiate Objects //////////////////////////////////////////////////////

TwoWire Wire = TwoWire();
