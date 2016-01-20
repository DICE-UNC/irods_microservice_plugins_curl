/* libmsiCurlEncodeStr.cpp
 *
 *  Created on: May 20, 2014
 *      Author: Mike Conway -DICE
 */



// =-=-=-=-=-=-=-
#include "irods_ms_plugin_curl.hpp"


// =-=-=-=-=-=-=-
// New microservice plugin definition style
MICROSERVICE_BEGIN(
	msiCurlUrlEncodeStr,
    STR, strToEncode, INPUT,
    STR, encodedStr, OUTPUT PTR NO_ALLOC )

    irods::error res = SUCCESS();

    // Create irodsCurl instance
    irodsCurl myCurl( rei->rsComm );

    // Call irodsCurl::get_str
    res = myCurl.encode_str( strToEncode, &encodedStr );

    // Done
    RETURN ( res.code());

MICROSERVICE_END
