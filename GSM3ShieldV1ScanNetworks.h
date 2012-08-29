/*
This file is part of the GSM3 communications library for Arduino
-- Multi-transport communications platform
-- Fully asynchronous
-- Includes code for the Arduino-Telefonica GSM/GPRS Shield V1
-- Voice calls
-- SMS
-- TCP/IP connections
-- HTTP basic clients

This library has been developed by Telefónica Digital - PDI -
- Physical Internet Lab, as part as its collaboration with
Arduino and the Open Hardware Community. 

September-December 2012

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

The latest version of this library can always be found at
http://www.tid.es
*/
#ifndef __GSM3SHIELDV1SCANNETWORKS__
#define __GSM3SHIELDV1SCANNETWORKS__

// This class executes band management functions for the ShieldV1
#include <GSM3ShieldV1AccessProvider.h>
#include <GSM3ShieldV1DirectModemProvider.h>

class GSM3ShieldV1ScanNetworks
{
	private:
		GSM3ShieldV1DirectModemProvider modem;
				
	public:
	
		/** Constructor
         @param trace if true, dumps all AT dialogue to Serial
		 @return - 
		*/
		GSM3ShieldV1ScanNetworks(bool trace=false);
		
		/** begin
			Forces modem hardware restart, so we begin from scratch
         @param 
		 @return Always returns IDLE status
		*/
		GSM3_NetworkStatus_t begin();

		/**
			Read current carrier
		 @param
		 @return Current carrier
		 */
		String getCurrentCarrier();
		
		/**
			Obtain signal strength
		 @param
		 @return Signal Strength
		 */
		String getSignalStrength();
		
		/**
			Search available carriers
		 @param
		 @return A string with list of networks available
		 */
		String readNetworks();
};
#endif