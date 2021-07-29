#pragma once
#ifndef MAPAS_H
#define MAPAS_H

#include <iostream>

namespace mapas {
	const int LONG_VEC_MAPA = 28;
}

namespace nivel_1 {
	void Nivel1(std::string v[28]) { //TODO: pasar el mapa a una libreria aparte
	//61 ancho
	//                111111111122222222223333333333444444444455555555556666666666777777777788888888889999999999
	//      01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
		v[0] = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX           ";//0
		v[1] = "X                                          XXX          XXXXXXXX                            X           ";//1
		v[2] = "X                        O          O             XXXX      P                               X           ";//2
		v[3] = "X    X    XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXDDXXX  XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX X           ";//3
		v[4] = "X    X    XX                                 X  XXX  XXX    X  X O                          X           ";//4
		v[5] = "X    X  XXXX                                 XK X           X  X XXXXXXXXXXXXXXXXXXXXXXXXXXXX           ";//5
		v[6] = "X    X  XXK                                  XXXX           X  X                            X           ";//6
		v[7] = "X    XXXXXXXXXXXXXXXXXXXXXXXXXX                             X  XXXXXXXXXXXXXXXXXXXXXXXXXXXX X           ";//7
		v[8] = "X                                      O                    X  X O                          X           ";//8
		v[9] = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX     X  X XXXXXXXXXXXXXXXXXXXXXXXXXXXX           ";//9
		v[10] = "X?   XXXXX        XXXX                     O          X     X  X                            X           ";//10
		v[11] = "X                          O      XXXX                X     X  XXXXXXXXXXXXXXXXXXXXXXXXXXXX X           ";//11
		v[12] = "X                 XXXX                     O                X  X O                          X           ";//12
		v[13] = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  X XXXXXXXXXXXXXXXXXXXXXXXXXXXX           ";//13
		v[14] = "                                                               X                            X           ";//14
		v[15] = "                                                               XXXXXXXXXXXXXXXXXXXXXXXXXXXX X           ";//15
		v[16] = "                                                               X O                          X           ";//16
		v[17] = "                                                               X XXXXXXXXXXXXXXXXXXXXXXXXXXXX           ";//17
		v[18] = "                                                               X                            X           ";//18
		v[19] = "                                                               XXXXXXXXXXXXXXXXXXXXXXXXXXXX X           ";//19
		v[20] = "                                                               X O                          X           ";//20
		v[21] = "                                                               X XXXXXXXXXXXXXXXXXXXXXXXXXXXX           ";//21
		v[22] = "                                                               X                            X           ";//22
		v[23] = "                                                               XXXXXXXXXXXXXXXXXXXXXXXXXXXX X           ";//23
		v[24] = "                                                               XF      O                    X           ";//24
		v[25] = "                                                               XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX           ";//25
		v[26] = "                                                                                                        ";//26
		v[27] = "                                                                                                        ";//27
		//v[28] = "                                                                                                        ";
	}
}

#endif // MAPAS_H
