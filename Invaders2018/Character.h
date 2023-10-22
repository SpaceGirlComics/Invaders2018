#ifndef CHARACTER_H
#define CHARACTER_H

/*player	= "000000000000000000000111111000000000000000000000000000000000000000001111111100000000000000000000000000000000000000011111111110000000000000000000000000000000000000011111111110000000000000000000000000000000000000011111111110000000000000000000000000000000000000011111111110000000000000000000000000000000000000011111111110000000000000000000000000000000000000011111111110000000000000000000000000000000000000011111111110000000000000000000000000000000000000011111111110000000000000000000000000000000000000011111111110000000000000000000000000000000000000011111111110000000000000000000020000000000000000011111111110000000000000000020022000000000000000011111111110000000000000000220022000000000000000111111111111000000000000000220022000000000000000111111111111000000000000000220022000000000000000111111111111000000000000000220022000000000000000111333333111000000000000000220022000000000000000113333333311000000000000000220022000000000000000113333333311000000000000000220022000000000000000113333333311000000000000000220022000000000000000113333333311000000000000000220022000000000000001113333333311100000000000000220022000000220000011113333333311110000022000000220022000000220000111113333333311111000022000000220022000000220001113113333333311311100022000000220022000000220011133133333333331331110022000000220222200000220111133133333333331331111022000002222222200000221111133133333333331331111122000002222223200000221111333111111111111333111122000002322222200001221111333111111111111333111122100002222222200111221111333111111111111333111122111002222222211111221111331111111111111133111122111112222222211111111111111111111111111111111111111112222222211111111111111111111111111111111111111112222222211111111111111111111111111111111111111112222222211111111111111111111111111111111111111112222211211111111111111111111111111111111111111112112222211111111111111111111111111111111111111112222222200000001111111111000000111111111100000002222000000000000111111110000000011111111000000000000000000000000444444440000000044444444000000000000000000000500444544440000004044454444500000000000000000000000445454440000000044545444040000000000000000000000455455450000050045545545000000000000000000000000055505404000000005550540000000000000000000000000000005500000000000000550000000000000000000000000000000000000000000000000000000000000000000000000000000000111111000000000000000000000000000000000000000001111111100000000000000000000000000000000000000011111111110000000000000000000000000000000000000011111111110000000000000000000000000000000000000011111111110000000000000000000000000000000000000011111111110000000000000000000000000000000000000011111111110000000000000000000000000000000000000011111111110000000000000000000000000000000000000011111111110000000000000000000000000000000000000011111111110000000000000000000000000000000000000011111111110000000000000000000000000000000000000011111111110000000000000000000020000000000000000011111111110000000000000000020022000000000000000011111111110000000000000000220022000000000000000111111111111000000000000000220022000000000000000111111111111000000000000000220022000000000000000111111111111000000000000000220022000000000000000111333333111000000000000000220022000000000000000113333333311000000000000000220022000000000000000113333333311000000000000000220022000000000000000113333333311000000000000000220022000000000000000113333333311000000000000000220022000000000000001113333333311100000000000000220022000000220000011113333333311110000022000000220022000000220000111113333333311111000022000000220022000000220001113113333333311311100022000000220022000000220011133133333333331331110022000000220222200000220111133133333333331331111022000002222222200000221111133133333333331331111122000002222223200000221111333111111111111333111122000002322222200001221111333111111111111333111122100002222222200111221111333111111111111333111122111002222222211111221111331111111111111133111122111112222222211111111111111111111111111111111111111112222222211111111111111111111111111111111111111112222222211111111111111111111111111111111111111112222222211111111111111111111111111111111111111112222211211111111111111111111111111111111111111112112222211111111111111111111111111111111111111112222222200000001111111111000000111111111100000002222000000000000111111110000000011111111000000000000000000000000444444440000000044444444000000000000000000000004454555454000000445455545400000000000000000000400455555540500000045555554000000000000000000000000455555540000040045555554000000000000000000000000055555500000000005555550000000000000000000000000005555000000000000555500050000000000000000000000000550000000000000055000000000000000000000000000000000000111111000000000000000000000000000000000000000001111111100000000000000000000000000000000000000011111111110000000000000000000000000000000000000011111111110000000000000000000000000000000000000011111111110000000000000000000000000000000000000011111111110000000000000000000000000000000000000011111111110000000000000000000000000000000000000011111111110000000000000000000000000000000000000011111111110000000000000000000000000000000000000011111111110000000000000000000000000000000000000011111111110000000000000000000000000000000000000011111111110000000000000000000020000000000000000011111111110000000000000000020022000000000000000011111111110000000000000000220022000000000000000111111111111000000000000000220022000000000000000111111111111000000000000000220022000000000000000111111111111000000000000000220022000000000000000111333333111000000000000000220022000000000000000113333333311000000000000000220022000000000000000113333333311000000000000000220022000000000000000113333333311000000000000000220022000000000000000113333333311000000000000000220022000000000000001113333333311100000000000000220022000000220000011113333333311110000022000000220022000000220000111113333333311111000022000000220022000000220001113113333333311311100022000000220022000000220011133133333333331331110022000000220222200000220111133133333333331331111022000002222222200000221111133133333333331331111122000002222223200000221111333111111111111333111122000002322222200001221111333111111111111333111122100002222222200111221111333111111111111333111122111002222222211111221111331111111111111133111122111112222222211111111111111111111111111111111111111112222222211111111111111111111111111111111111111112222222211111111111111111111111111111111111111112222222211111111111111111111111111111111111111112222211211111111111111111111111111111111111111112112222211111111111111111111111111111111111111112222222200000001111111111000000111111111100000002222000000000000111111110000000011111111000000000000000000000000444444440000000044444444000000000000000000000050445454540000000045454544000000000000000000000000455454540000000045454554000000000000000000000000055455550000000055554550000000000000000000000000055505500000000405555550000000000000000000000000050505504000000005505050000000000000000000000000000500050000000040005000500000000000";
bullet		= "11111111111111111111111111111111111111112233223322223322332244224422444422442244040400400400500500501111111111111111111111111111111111111111332233223333223322332244224422224422442240404004000500500505"
vanilla		= "000000000000000110000000000000011000000000000000000000000000111100000000000000001111000000000000000000000001111000000000000000000111100000000000000000000011111000000000000000000111110000000000000000000111111000000000000000000111111000000000000000000111111100000000000000001111111000000000000000011111111111111111111111111111111110000000000011111111111111111111111111111111111111110000000111111111111111111111111111111111111111111000001111111111111111111111111111111111111111111100011111111111111111111111111111111111111111111110111111111111111111111111111111111111111111111111111111111110000000011111111110000000011111111111111111111110000000011111111110000000011111111111111111111110000000011111111110000000011111111111111111111110000000011111111110000000011111111111111111111110000000011111111110000000011111111111111111111110000000011111111110000000011111111111111111111110000000011111111110000000011111111111111111011110000000011111111110000000011110111111111111011111111111111111111111111111111110111111111111011111111111111111111111111111111110111111111111011111111111111111111111111111111110111111111111011111111111111111111111111111111110111111111111011111111111111111111111111111111110111111111111000111111000000000000000000111111000111111111111000111111000000000000000000111111000111111111111000111111000000000000000000111111000111111000000000000111111000000000000111111000000000000000000000000111111000000000000111111000000000000000000000000111111000000000000111111000000000000000000000000000110000000000000011000000000000000000000000000111100000000000000001111000000000000000000000001111000000000000000000111100000000000000000000011111000000000000000000111110000000000000000000111111000000000000000000111111000000000000000000111111100000000000000001111111000000000000000011111111111111111111111111111111110000000000011111111111111111111111111111111111111110000000111111111111111111111111111111111111111111000001111111111111111111111111111111111111111111100011111111111111111111111111111111111111111111110111111111111111111111111111111111111111111111111111111111110000000011111111110000000011111111111111111111110000000011111111110000000011111111111111111111110000000011111111110000000011111111111111111111110000000011111111110000000011111111111111111111110000000011111111110000000011111111111111111111110000000011111111110000000011111111111111111111110000000011111111110000000011111111111111111011110000000011111111110000000011110111111111111011111111111111111111111111111111110111111111111011111111111111111111111111111111110111111111111011111111111111111111111111111111110111111111111011111111111111111111111111111111110111111111111011111111111111111111111111111111110111111111111000000111111000000000000111111000000111111111111000000111111000000000000111111000000111111111111000000111111000000000000111111000000111111000000000111111000000000000000000111111000000000000000000111111000000000000000000111111000000000000000000111111000000000000000000111111000000000000000000000000110000000000000011000000000000000000000000000111100000000000000001111000000000000000000000001111000000000000000000111100000000000000000000011111000000000000000000111110000000000000000000111111000000000000000000111111000000000000000000111111100000000000000001111111000000000000000011111111111111111111111111111111110000000000011111111111111111111111111111111111111110000000111111111111111111111111111111111111111111000001111111111111111111111111111111111111111111100011111111111111111111111111111111111111111111110111111111111111111111111111111111111111111111111111111111110000000011111111110000000011111111111111111111110000000011111111110000000011111111111111111111110000000011111111110000000011111111111111111111110000000011111111110000000011111111111111111111110000000011111111110000000011111111111111111111110000000011111111110000000011111111111111111111110000000011111111110000000011111111111111111011110000000011111111110000000011110111111111111011111111111111111111111111111111110111111111111011111111111111111111111111111111110111111111111011111111111111111111111111111111110111111111111011111111111111111111111111111111110111111111111011111111111111111111111111111111110111111111111000001111110000000000000011111100000111111111111000001111110000000000000011111100000111111111111000001111110000000000000011111100000111111000000000001111110000000000000011111100000000000000000000001111110000000000000011111100000000000000000000001111110000000000000011111100000000000"
shield		= "0000000000000000000111111111111111111111111111111111110000000000000000000000000000000000000111111111111111111111111111111111111100000000000000000000000000000000000111111111111111111111111111111111111111000000000000000000000000000000000111111111111111111111111111111111111111110000000000000000000000000000000111111111111111111111111111111111111111111100000000000000000000000000000111111111111111111111111111111111111111111111000000000000000000000000000111111111111111111111111111111111111111111111110000000000000000000000000111111111111111111111111111111111111111111111111100000000000000000000000111111111111111111111111111111111111111111111111111000000000000000000000111111111111111111111111111111111111111111111111111110000000000000000000111111111111111111111111111111111111111111111111111111100000000000000000111111111111111111111111111111111111111111111111111111111000000000000000111111111111111111111111111111111111111111111111111111111110000000000000111111111111111111111111111111111111111111111111111111111111100000000000111111111111111111111111111111111111111111111111111111111111111000000000111111111111111111111111111111111111111111111111111111111111111110000000111111111111111111111111111111111111111111111111111111111111111111100000111111111111111111111111111111111111111111111111111111111111111111111000111111111111111111111111111111111111111111111111111111111111111111111110111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110000000000000000000001111111111111111111111111111111111111111111111111110000000000000000000000011111111111111111111111111111111111111111111111110000000000000000000000000111111111111111111111111111111111111111111111110000000000000000000000000001111111111111111111111111111111111111111111110000000000000000000000000000011111111111111111111111111111111111111111110000000000000000000000000000000111111111111111111111111111111111111111111000000000000000000000000000000011111111111111111111111111111111111111111100000000000000000000000000000001111111111111111111111111111111111111111110000000000000000000000000000000111111111111111111111111111111111111111111000000000000000000000000000000011111111111111111111111111111111111111111100000000000000000000000000000001111111111111111111111111111111111111111110000000000000000000000000000000111111111111111111111111111111111111111111000000000000000000000000000000011111111111111111111111111111111111111111100000000000000000000000000000001111111111111111111110111111111111111111100000000000000000000000000000000011111111111111111110001111111111111111100000000000000000000000000000000000111111111111111110000011111111111111100000000000000000000000000000000000001111111111111110000000111111111111100000000000000000000000000000000000000011111111111110000"
screwy		= "000000000000000110000000000000011000000000000000000000000000111100000000000000001111000000000000000000000001111000000000000000000111100000000000000000000011111000000000000000000111110000000000000000000111111000000000000000000111111000000000000000000111111100000000000000001111111000000000000000011111111111111111111111111111111110000000000011111111111111111111111111111111111111110000000111111111111111111111111111111111111111111000001111111111111111111111111111111111111111111100011111111111111000000111111111111111111111111110111111111111111000000111111111111111111111111111111111111111111000000111111111111111111111111111111111111111111000000111111000000111111111111111111111111111111000000111111000000111111111111111111111111111111000000111111000000111111111111111111111111111111111111111111000000111111111111111111111111101111111111111111000000111110111111111111111111010011111111111111000000111001011111111111111011111100001111111111111100000111110111111111111011111111110000000000000010111011110111111111111011111111111111111111011111011101110111111111111011111111111111111111101111101110110111111111111011111111111111111111110001111110110111111111111011111111111111111111111110000011110111111111111000111111000000000000000000111111000111111111111000111111000000000000000000111111000111111111111000111111000000000000000000111111000111111000000000000111111000000000000111111000000000000000000000000111111000000000000111111000000000000000000000000111111000000000000111111000000000000000000000000000110000000000000011000000000000000000000000000111100000000000000001111000000000000000000000001111000000000000000000111100000000000000000000011111000000000000000000111110000000000000000000111111000000000000000000111111000000000000000000111111100000000000000001111111000000000000000011111111111111111111111111111111110000000000011111111111111111111111111111111111111110000000111111111111111111111111111111111111111111000001111111111111111111111111111111111111111111100011111111111111111111111111111111111111111111110111111111111111110000001100000011111111111111111111111111111111110000001100000011111111111111111111111111111111110000001100000011111111111111111111111111111111110000001100000011111111111111111111111111111111110000001100000011111111111111111111111111111111110000001100000011111111111111111111111111101111111111111111111111111101111111111111111111010011111111111111111111110010111111111111111011111100001111111111111100000111110111111111111011111111110000000000000010111011110111111111111011111111111111111111011111011101110111111111111011111111111111111111101111101110110111111111111011111111111111111111110001111110110111111111111011111111111111111111111110000011110111111111111000000111111000000000000111111000000111111111111000000111111000000000000111111000000111111111111000000111111000000000000111111000000111111000000000111111000000000000000000111111000000000000000000111111000000000000000000111111000000000000000000111111000000000000000000111111000000000000000000000000110000000000000011000000000000000000000000000111100000000000000001111000000000000000000000001111000000000000000000111100000000000000000000011111000000000000000000111110000000000000000000111111000000000000000000111111000000000000000000111111100000000000000001111111000000000000000011111111111111111111111111111111110000000000011111111111111111111111111111111111111110000000111111111111111111111111111111111111111111000001111111111111111111111111111111111111111111100011111111111111111111111111000000111111111111110111111111111111111111111111000000111111111111111111111111111111111111111111000000111111111111111111111111111111000000111111000000111111111111111111111111111111000000111111000000111111111111111111111111111111000000111111000000111111111111111111111111111111000000111111111111111111111111111111111111101111000000111111111111111110111111111111111111010011000000111111111111111001011111111111111011111100001111111111111100000111110111111111111011111111110000000000000010111011110111111111111011111111111111111111011111011101110111111111111011111111111111111111101111101110110111111111111011111111111111111111110001111110110111111111111011111111111111111111111110000011110111111111111000001111110000000000000011111100000111111111111000001111110000000000000011111100000111111111111000001111110000000000000011111100000111111000000000001111110000000000000011111100000000000000000000001111110000000000000011111100000000000000000000001111110000000000000011111100000000000000000000000000110000000000000011000000000000000000000000000111100000000000000001111000000000000000000000001111000000000000000000111100000000000000000000011111000000000000000000111110000000000000000000111111000000000000000000111111000000000000000000111111100000000000000001111111000000000000000011111111111111111111111111111111110000000000011111111111111111111111111111111111111110000000111111111111111111111111111111111111111111000001111111111111111111111111111111111111111111100011111111111111111111111111111111111111111111110111111111111111110000001100000011111111111111111111111111111111110000001100000011111111111111111111111111111111110000001100000011111111111111111111111111111111110000001100000011111111111111111111111111111111110000001100000011111111111111111111111111111111110000001100000011111111111111111111111111101111111111111111111111111101111111111111111111010011111111111111111111110010111111111111111011111100001111111111111100000111110111111111111011111111110000000000000010111011110111111111111011111111111111111111011111011101110111111111111011111111111111111111101111101110110111111111111011111111111111111111110001111110110111111111111011111111111111111111111110000011110111111111111000000111111000000000000111111000000111111111111000000111111000000000000111111000000111111111111000000111111000000000000111111000000111111000000000111111000000000000000000111111000000000000000000111111000000000000000000111111000000000000000000111111000000000000000000111111000000000"
glass		= "000000000000000110000000000000011000000000000000000000000000111100000000000000001111000000000000000000000001111000000000000000000111100000000000000000000011111000000000000000000111110000000000000000000111111000000000000000000111111000000000000000000111111100000000000000001111111000000000000000011111111111111111111111111111111110000000000011111111111111111111111111111111111111110000000111111111111111111111111111111111111111111000001111111111111111111111111111111111111111111100011111111111111111111111111111111111111111111110111111111111111111111111111111111111111111111111111111111100000000000111111000000000001111111111111111111000000000000011110000000000000111111111111111111001111111110011110011111111100111111111111111111001111111110011110011111111100111111111111111111001111111110011110011111111100111111111111111111000011111110011110000111111100111111111111111111000001111110000000000011111100111111111111111011000001111110011110000011111100110111111111111000000011111110011110000111111100000111111111111011000000000000011110000000000000110111111111111011100000000000111111000000000001110111111111111011111111111111111111111111111111110111111111111011111111111111111111111111111111110111111111111000111111000000000000000000111111000111111111111000111111000000000000000000111111000111111111111000111111000000000000000000111111000111111000000000000111111000000000000111111000000000000000000000000111111000000000000111111000000000000000000000000111111000000000000111111000000000000000000000000000110000000000000011000000000000000000000000000111100000000000000001111000000000000000000000001111000000000000000000111100000000000000000000011111000000000000000000111110000000000000000000111111000000000000000000111111000000000000000000111111100000000000000001111111000000000000000011111111111111111111111111111111110000000000011111111111111111111111111111111111111110000000111111111111111111111111111111111111111111000001111111111111111111111111111111111111111111100011111111111111111111111111111111111111111111110111111111111111111111111111111111111111111111111111111111100000000000111111000000000001111111111111111111000000000000011110000000000000111111111111111111001111111110011110011111111100111111111111111111001111111110011110011111111100111111111111111111001111111110011110011111111100111111111111111111001111001110011110011100111100111111111111111111001110000110000000011000011100111111111111111011001110000110011110011000011100110111111111111000001111001110011110011100111100000111111111111011000000000000011110000000000000110111111111111011100000000000111111000000000001110111111111111011111111111111111111111111111111110111111111111011111111111111111111111111111111110111111111111000000111111000000000000111111000000111111111111000000111111000000000000111111000000111111111111000000111111000000000000111111000000111111000000000111111000000000000000000111111000000000000000000111111000000000000000000111111000000000000000000111111000000000000000000111111000000000000000000000000110000000000000011000000000000000000000000000111100000000000000001111000000000000000000000001111000000000000000000111100000000000000000000011111000000000000000000111110000000000000000000111111000000000000000000111111000000000000000000111111100000000000000001111111000000000000000011111111111111111111111111111111110000000000011111111111111111111111111111111111111110000000111111111111111111111111111111111111111111000001111111111111111111111111111111111111111111100011111111111111111111111111111111111111111111110111111111111111111111111111111111111111111111111111111111100000000000111111000000000001111111111111111111000000000000011110000000000000111111111111111111001111111110011110011111111100111111111111111111001111111110011110011111111100111111111111111111001111111110011110011111111100111111111111111111001111111000011110011111110000111111111111111111001111110000000000011111100000111111111111111011001111110000011110011111100000110111111111111000001111111000011110011111110000000111111111111011000000000000011110000000000000110111111111111011100000000000111111000000000001110111111111111011111111111111111111111111111111110111111111111011111111111111111111111111111111110111111111111000001111110000000000000011111100000111111111111000001111110000000000000011111100000111111111111000001111110000000000000011111100000111111000000000001111110000000000000011111100000000000000000000001111110000000000000011111100000000000000000000001111110000000000000011111100000000000000000000000000110000000000000011000000000000000000000000000111100000000000000001111000000000000000000000001111000000000000000000111100000000000000000000011111000000000000000000111110000000000000000000111111000000000000000000111111000000000000000000111111100000000000000001111111000000000000000011111111111111111111111111111111110000000000011111111111111111111111111111111111111110000000111111111111111111111111111111111111111111000001111111111111111111111111111111111111111111100011111111111111111111111111111111111111111111110111111111111111111111111111111111111111111111111111111111100000000000111111000000000001111111111111111111000000000000011110000000000000111111111111111111001111111110011110011111111100111111111111111111001111111110011110011111111100111111111111111111001111111110011110011111111100111111111111111111001111001110011110011100111100111111111111111111001110000110000000011000011100111111111111111011001110000110011110011000011100110111111111111000001111001110011110011100111100000111111111111011000000000000011110000000000000110111111111111011100000000000111111000000000001110111111111111011111111111111111111111111111111110111111111111011111111111111111111111111111111110111111111111000000111111000000000000111111000000111111111111000000111111000000000000111111000000111111111111000000111111000000000000111111000000111111000000000111111000000000000000000111111000000000000000000111111000000000000000000111111000000000000000000111111000000000000000000111111000000000"
chipped		= "000000000000000110000000000000000000000000000000000000000000111100000000000000000000000000000000000000000001111000000000000000000000100000000000000000000011111000000000000000000111110000000000000000000111111000000000000000000111111000000000000000000111111100000000000000001111111000000000000000011111111111111111111111111111111110000000000011111111111111111111111111111111111111110000000111111111111111111111111111111111111111111000001111111111111111111111111111111111111111111100011111111111111111111111111111111111111111111110111111111111111111111111111111111111111111111111111111111110000000011111111110000000011111111111111111111110000000011111111110000000011111111111111111111110000000011111111110000000011111111111111111111110000000011111111110000000011111111111111111111110000000011111111110000000011111111111111111111110000000011111111110000000011111111111111111111110000000011111111110000000011111111111111111011110000000011111111110000000011110111111111111011111111111111111111111111111111110111111111111011111111111111111111111111111111110111111111111011111111111111111111111111111111110111111111111011111111111111111111111111111111110111111111111011111111111111111111111111111111110111111111111000111111000000000000000000111111000111111111111000111111000000000000000000111111000111111111111000111111000000000000000000111111000111111000000000000111111000000000000111111000000000000000000000000111111000000000000111111000000000000000000000000111111000000000000111111000000000000000000000000000110000000000000000000000000000000000000000000111100000000000000000000000000000000000000000001111000000000000000000000100000000000000000000011111000000000000000000111110000000000000000000111111000000000000000000111111000000000000000000111111100000000000000001111111000000000000000011111111111111111111111111111111110000000000011111111111111111111111111111111111111110000000111111111111111111111111111111111111111111000001111111111111111111111111111111111111111111100011111111111111111111111111111111111111111111110111111111111111111111111111111111111111111111111111111111110000000011111111110000000011111111111111111111110000000011111111110000000011111111111111111111110000000011111111110000000011111111111111111111110000000011111111110000000011111111111111111111110000000011111111110000000011111111111111111111110000000011111111110000000011111111111111111111110000000011111111110000000011111111111111111011110000000011111111110000000011110111111111111011111111111111111111111111111111110111111111111011111111111111111111111111111111110111111111111011111111111111111111111111111111110111111111111011111111111111111111111111111111110111111111111011111111111111111111111111111111110111111111111000000111111000000000000111111000000111111111111000000111111000000000000111111000000111111111111000000111111000000000000111111000000111111000000000111111000000000000000000111111000000000000000000111111000000000000000000111111000000000000000000111111000000000000000000111111000000000000000000000000110000000000000000000000000000000000000000000111100000000000000000000000000000000000000000001111000000000000000000000100000000000000000000011111000000000000000000111110000000000000000000111111000000000000000000111111000000000000000000111111100000000000000001111111000000000000000011111111111111111111111111111111110000000000011111111111111111111111111111111111111110000000111111111111111111111111111111111111111111000001111111111111111111111111111111111111111111100011111111111111111111111111111111111111111111110111111111111111111111111111111111111111111111111111111111110000000011111111110000000011111111111111111111110000000011111111110000000011111111111111111111110000000011111111110000000011111111111111111111110000000011111111110000000011111111111111111111110000000011111111110000000011111111111111111111110000000011111111110000000011111111111111111111110000000011111111110000000011111111111111111011110000000011111111110000000011110111111111111011111111111111111111111111111111110111111111111011111111111111111111111111111111110111111111111011111111111111111111111111111111110111111111111011111111111111111111111111111111110111111111111011111111111111111111111111111111110111111111111000001111110000000000000011111100000111111111111000001111110000000000000011111100000111111111111000001111110000000000000011111100000111111000000000001111110000000000000011111100000000000000000000001111110000000000000011111100000000000000000000001111110000000000000011111100000000000"
meow		= "000000000000110000000000000000000011000000000000000000000001111000000000000000000111100000000000000000000011001100000000000000001100110000000000000000000110000110000000000000011000011000000000000000001100000011000000000000110000001100000000000000011111111111100000000001111111111110000000000000011111111111111111111111111111111110000000000011111111111111111111111111111111111111110000000111111111111111111111111111111111111111111000001111111110000000011111111110000000011111111100011111111110000000011111111110000000011111111110111111111110001100011111111110001100011111111111111111111110001100011111111110001100011111111111111111111110001100011111111110001100011111111111111111111110001100011111111110001100011111111111111111111110001100011111111110001100011111111111111111111110000000011100001110000000011111111111111111111111111111111110011111111111111111111111111111111110111011111110011111110111011111111111111111011111101111001100001100111101111110111111111111011111111111100001100001111111111110111111111111011111111111111111111111111111111110111111111111011111111111111111111111111111111110111111111111011111111111111111111111111111111110111111111111011111111111111111111111111111111110111111111111000111111000000000000000000111111000111111111111000111111000000000000000000111111000111111111111000111111000000000000000000111111000111111000000000000111111000000000000111111000000000000000000000000111111000000000000111111000000000000000000000000111111000000000000111111000000000000000000000000110000000000000000000011000000000000000000000001111000000000000000000111100000000000000000000011001100000000000000001100110000000000000000000110000110000000000000011000011000000000000000001100000011000000000000110000001100000000000000011000000001100000000001100000000110000000000000011111111111111111111111111111111110000000000011111111111111111111111111111111111111110000000111111111111111111111111111111111111111111000001111111110000000011111111110000000011111111100011111111110000000011111111110000000011111111110111111111110001100011111111110001100011111111111111111111110001100011111111110001100011111111111111111111110001100011111111110001100011111111111111111111110001100011111111110001100011111111111111111111110001100011111111110001100011111111111111111111110000000011100001110000000011111111111111111111111111111111110011111111111111111111111111111111110111011111110011111110111011111111111111111011111101111001100001100111101111110111111111111011111111111100000000001111111111110111111111111011111111111111000000111111111111110111111111111011111111111111111111111111111111110111111111111011111111111111111111111111111111110111111111111011111111111111111111111111111111110111111111111000001111110000000000000011111100000111111111111000001111110000000000000011111100000111111111111000001111110000000000000011111100000111111000000000001111110000000000000011111100000000000000000000001111110000000000000011111100000000000000000000001111110000000000000011111100000000000000000000000110000000000000000000011000000000000000000000001111000000000000000000111100000000000000000000011001100000000000000001100110000000000000000000110000110000000000000011000011000000000000000001100000011000000000000110000001100000000000000011111111111100000000001111111111110000000000000011111111111111111111111111111111110000000000011111111111111111111111111111111111111110000000111111111111111111111111111111111111111111000001111111110000000011111111110000000011111111100011111111110000000011111111110000000011111111110111111111110001100011111111110001100011111111111111111111110001100011111111110001100011111111111111111111110001100011111111110001100011111111111111111111110001100011111111110001100011111111111111111111110001100011111111110001100011111111111111111111110000000011100001110000000011111111111111111111111111111111110011111111111111111111111111111111110111011111110011111110111011111111111111111011111101111001100001100111101111110111111111111011111111111100000000001111111111110111111111111011111111111101000000101111111111110111111111111011111111111110000000011111111111110111111111111011111111111111010010111111111111110111111111111011111111111111111111111111111111110111111111111000000111111000000000000111111000000111111111111000000111111000000000000111111000000111111111111000000111111000000000000111111000000111111000000000111111000000000000000000111111000000000000000000111111000000000000000000111111000000000000000000111111000000000000000000111111000000000000000000000110000000000000000000011000000000000000000000001111000000000000000000111100000000000000000000011001100000000000000001100110000000000000000000110000110000000000000011000011000000000000000001100000011000000000000110000001100000000000000011000000001100000000001100000000110000000000000011111111111111111111111111111111110000000000011111111111111111111111111111111111111110000000111111111111111111111111111111111111111111000001111111110000000011111111110000000011111111100011111111110000000011111111110000000011111111110111111111110001100011111111110001100011111111111111111111110001100011111111110001100011111111111111111111110001100011111111110001100011111111111111111111110001100011111111110001100011111111111111111111110001100011111111110001100011111111111111111111110000000011100001110000000011111111111111111111111111111111110011111111111111111111111111111111110111011111110011111110111011111111111111111011111101111001100001100111101111110111111111111011111111111100000000001111111111110111111111111011111111111111000000111111111111110111111111111011111111111111111111111111111111110111111111111011111111111111111111111111111111110111111111111011111111111111111111111111111111110111111111111000001111110000000000000011111100000111111111111000001111110000000000000011111100000111111111111000001111110000000000000011111100000111111000000000001111110000000000000011111100000000000000000000001111110000000000000011111100000000000000000000001111110000000000000011111100000000000"
*/

class Character
{
	public:
		Character();

		virtual int initialize() = 0;

		virtual int update(int delta) = 0;
		int** getFrameData();

		int getX();
		int getY();
		int getWidth();
		int getHeight();

		void translate(int _x, int _y);

		~Character();
	protected:
		int*** img;

		int frame;
		int minFrame;
		int maxFrame;
		int totalFrames;
		int frameTime;
		int fps;

		int width;
		int height;
		int x;
		int y;
		float scale;

		int hp;
		int state;

		int pallet[6];

		int lifeTime;

		int accel;
		int deccl;
		int xspeed;
};


#endif
