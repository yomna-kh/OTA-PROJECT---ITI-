#include "LIB/STD_TYPES.h"
#define COLS 45
#define ROWS 346


char array[][COLS]= {
		":020000040800F2",
		":1000000000000120C5020008CB020008CF02000852",
		":1000100041030008450300088D03000800000000AC",
		":10002000000000000000000000000000D5030008F0",
		":10003000D903000800000000DD030008E506000801",
		":10004000F1030008F1030008F1030008F1030008C0",
		":10005000F1030008F1030008F1030008F1030008B0",
		":10006000F1030008F1030008F1030008F1030008A0",
		":10007000F1030008F1030008F1030008F103000890",
		":10008000F1030008F1030008F1030008000000007C",
		":10009000000000000000000000000000F103000864",
		":1000A000F1030008F1030008F1030008F103000860",
		":1000B000F1030008F1030008F1030008F103000850",
		":1000C000F1030008F1030008F1030008F103000840",
		":1000D000F10300087D0600089906000800000000F2",
		":1000E000F1030008F1030008F1030008000000001C",
		":1000F000000000000000000000000000F103000804",
		":1001000000000000F1030008F1030008F1030008FB",
		":1001100000000000000000000000000000000000DF",
		":10012000F1030008F1030008F1030008F1030008DF",
		":10013000F1030008000000000000000000000000C3",
		":10014000000000000000000000000000F1030008B3",
		":10015000F1030008F1030008F1030008B5060008E8",
		":10016000F1030008F1030008000000000000000097",
		":10017000000000000000000000000000000000007F",
		":1001800000000000F1030008000000000000000073",
		":10019000F103000800B583B000F0BAF9384B394AD2",
		":1001A0001360394A1360394900E02146384B9942BF",
		":1001B0000BD20A684B6801F10C0488689842F4D9A4",
		":1001C0001168196004330432F8E72E4B1A68314B7A",
		":1001D0009A4200D0FEE72C4B1A682F4B9A42F9D175",
		":1001E000274B2E4A13602E4A13602E4B05E0002049",
		":1001F000106004329342FAD80B462B4A934204D241",
		":10020000194651F8082B5B68F4E7244B1B6813B9B7",
		":10021000234B1B6803B1FEE700F008FC694601A808",
		":1002200000F022F9214C224BE41AA4100025AC4224",
		":1002300014DC204C204BE41AA4100025AC4213DC43",
		":100240000099019800F0F3FB05461C4C1C4BE41A86",
		":10025000A410002C0EDC284600F0E2F8144B53F8F2",
		":10026000253098470135E2E7134B53F8253098477E",
		":100270000135E3E7013C124B53F824309847E8E797",
		":10028000BABADECA0000002070000020F4030008A3",
		":100290000C0400087856341232547698740000200A",
		":1002A000200100200C0400081C0400081C040008A5",
		":1002B0001C0400081C0400081C0400081C0400089E",
		":1002C0001C04000808B5FFF765FF00BEFEE71EF03E",
		":1002D000040F0CBFEFF30880EFF309807146414A29",
		":1002E00010472DE9F04182B004468846124B5E6B00",
		":1002F0009F6B9D6A1B6B13F0020F03D00E4BDB6AE2",
		":10030000002B0CDB0D4800F0B7F8CDF800803B4621",
		":1003100032462946204600F007F900BEFEE74BF6BC",
		":10032000AB6100F07BF90028ECD0034B4FF00042AA",
		":10033000DA6202B0BDE8F08100ED00E0741400085C",
		":1003400000BEFEE71EF0040F0CBFEFF30880EFF3D2",
		":1003500009807146244A10472DE9F04182B00446D5",
		":100360008846084B5E6B9F6B9D6A074800F084F8D7",
		":10037000CDF800803B4632462946204600F0D4F8AE",
		":1003800000BEFEE700ED00E0841400081EF0040F3C",
		":100390000CBFEFF30880EFF309807146134A104752",
		":1003A0002DE9F04182B004468846084B5E6B9F6B96",
		":1003B0009D6A074800F060F8CDF800803B46324661",
		":1003C0002946204600F0B0F800BEFEE700ED00E050",
		":1003D0009014000800BEFEE700BEFEE700BEFEE788",
		":1003E00070470000E302000859030008A103000859",
		":0403F00000BEFEE766                        ",
		":1003F400D41400080000002074000020D414000865",
		":1004040000000010000000107400002024010020EF",
		":080414000000001000000010C0                ",
		":10042000FEE7000008B503460C4A12685AB10B4AB1",
		":100430001068033323F003030344094A934206D8A8",
		":10044000064A136008BD054A06491160EFE700F04F",
		":100450000BFB0C2303604FF0FF30F3E77800002024",
		":1004600000FC00202401002001230360014B0B60ED",
		":10047000704700BF040000200FB400B583B004AB88",
		":1004800053F8042B01938021064800F01FFB00283D",
		":1004900003DD0146034800F037F803B05DF804EBD4",
		":1004A00004B07047800000202DE9F04385B0044679",
		":1004B0000F4643560BB10E461EE004252846214642",
		":1004C000ABBE0446384605B0BDE8F08314F9011B05",
		":1004D00004AA1A4402F8101C0133AB42F6D304AA52",
		":1004E0001344002203F8102C4FF00408E94640465C",
		":1004F0004946ABBE8046761B002EE3D03546102E13",
		":1005000028BF10250023E8E708B5FFF7CDFF08BD99",
		":1005100008B500F093F8024A024B9A6008BD00BF8C",
		":100520000000000800ED00E0F8B504460D4617464F",
		":100530001E462748FFF7A0FF21682648FFF79CFFCB",
		":1005400061682548FFF798FFA1682448FFF794FFEA",
		":10055000E1682348FFF790FF21692248FFF78CFFED",
		":1005600061692148FFF788FFA1692048FFF784FFF0",
		":10057000E1691F48FFF780FF1E48FFF77DFF29460E",
		":100580001D48FFF779FF1D4CE16A1D48FFF774FF16",
		":10059000216B1C48FFF770FFE16B1B48FFF76CFFF6",
		":1005A00015F0800F0AD115F4004F0CD11748FFF752",
		":1005B00063FF06991648FFF75FFFF8BD39461548F7",
		":1005C000FFF75AFFEFE731461348FFF755FFEDE716",
		":1005D00058130008681300087813000888130008EF",
		":1005E00098130008A8130008B8130008C8130008DF",
		":1005F000D8130008E8130008F413000800ED00E029",
		":1006000004140008141400082414000854140008EA",
		":100610005C140008341400084414000883691A8824",
		":100620008A4201D0002070470268033A012A03D8A9",
		":100630000233836101207047002070470C4B1A6819",
		":1006400042F001021A60002199601A6822F0847257",
		":1006500022F480321A60074A5A601A6822F4802213",
		":100660001A60D960044B4FF000629A60704700BF77",
		":10067000003802401030002400ED00E008B5044BC3",
		":1006800000221A60034B1B6803B1984708BD00BFE6",
		":10069000001001401801002008B5044B00221A6028",
		":1006A000034B1B6803B1984708BD00BF00440040DE",
		":1006B0001001002008B5044B00221A60034B1B6890",
		":1006C00003B1984708BD00BF001401401401002089",
		":1006D000034B00229A601A6822F001021A607047E8",
		":1006E00010E000E008B5084B1B6803B19847074BC2",
		":1006F0001B7813B1064B1B6808BD044B01221A700E",
		":10070000FFF7E6FFF6E700BF000100201C01002014",
		":1007100010E000E0174B1A6822F400221A609A6871",
		":1007200022F001029A609A6822F002029A609A68A6",
		":1007300022F0F0029A609A6842F080029A609A6809",
		":1007400022F4E0529A609A689A609A6822F46042B1",
		":100750009A609A689A601A6842F001021A60054B22",
		":100760001B6813F0020FFAD0024A136823F080735B",
		":1007700013607047003802400138072844D8DFE88A",
		":1007800000F0040C141C242C343C2048036B012280",
		":1007900002FA01F11943016370471C48436B0122BF",
		":1007A00002FA01F11943416370471848036C0122B2",
		":1007B00002FA01F11943016470471448436C0122A5",
		":1007C00002FA01F11943416470471048036D012298",
		":1007D00002FA01F11943016570470C48436D01228B",
		":1007E00002FA01F11943416570470848036E01227E",
		":1007F00002FA01F11943016670470448436E012271",
		":1008000002FA01F119434166704700BF0038024007",
		":100810000F2934D8032A32D810B4022813D0032861",
		":100820001FD0012801D010BC7047154B1868490033",
		":1008300003248C4020EA04001860186802FA01F1D1",
		":1008400001431960EFE70F4B1868490003248C40FF",
		":1008500020EA04001860186802FA01F101431960E7",
		":10086000E1E7094B1868490003248C4020EA0400A2",
		":100870001860186802FA01F101431960D3E7704764",
		":10088000000002400004024000080240022A02D098",
		":10089000012A21D0704702280CD0032813D0012848",
		":1008A000F8D11C484368012202FA01F123EA010150",
		":1008B0004160704718484368012202FA01F123EAB7",
		":1008C00001014160704715484368012202FA01F1B5",
		":1008D00023EA01014160704702280AD0032810D0A2",
		":1008E0000128D7D10B48436802FA01F1194341604E",
		":1008F000704709484368012202FA01F11943416037",
		":10090000704706484368012202FA01F11943416029",
		":10091000C0E700BF0000024000040240000802409F",
		":100920000F2934D8032A32D810B4022813D0032850",
		":100930001FD0012801D010BC7047154B98684900A2",
		":1009400003248C4020EA04009860986802FA01F1C0",
		":1009500001439960EFE70F4B9868490003248C40EE",
		":1009600020EA04009860986802FA01F10143996056",
		":10097000E1E7094B9868490003248C4020EA040011",
		":100980009860986802FA01F101439960D3E77047D3",
		":10099000000002400004024000080240012A07D083",
		":1009A0002AB902282AD0032831D001281DD0704747",
		":1009B00002280AD0032810D00128F8D1184843692A",
		":1009C00002FA01F119434161704716484369012257",
		":1009D00002FA01F11943416170471348436901224A",
		":1009E00002FA01F11943416170470D484369012240",
		":1009F00002FA01F123EA01014161704709484369A4",
		":100A0000012202FA01F123EA01014161704706481F",
		":100A10004369012202FA01F123EA01014161C6E7BB",
		":100A2000000002400004024000080240704708B580",
		":100A3000FFF770FE00210120FFF79EFE012200213A",
		":100A40001046FFF7E5FE022200210120FFF71EFFFE",
		":100A5000002211460120FFF763FF0122002110460A",
		":100A6000FFF79CFFF9E70000014B1868704700BFD3",
		":100A70000C00002030B5141E05469BB0184605DA60",
		":100A80008B232B604FF0FF301BB030BD4FF402734F",
		":100A9000ADF80C3014BF04F1FF33234602930593E5",
		":100AA0004FF6FF7300910491ADF80E3002461E9B85",
		":100AB0006946284600F072F8431CBCBF8B232B60AC",
		":100AC000002CE1D0009B00221A70DDE707B50093EF",
		":100AD00013460A46014603480068FFF7CBFF03B000",
		":100AE0005DF804FB0C0000202DE9F0478E689E4263",
		":100AF00082460C469046994637D88A8912F4906F00",
		":100B000031D0256809696F1A6569022305EB45052F",
		":100B100095FBF3F509F101033B449D4238BF1D46A7",
		":100B2000530530D5294600F07DFB064650B90C230D",
		":04154400325476980F",
		":040000050800019559",
		":00000001FF"

};
