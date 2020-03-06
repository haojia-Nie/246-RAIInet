//
//  info.hpp
//  a555
//
//  Created by Sapphire Nie on 2019-11-24.
//  Copyright © 2019 Stellar Pan. All rights reserved.
//

#ifndef __INFO_H__
#define __INFO_H__
#include <cstddef>

struct Info {
    int row, col;
    int owner;
    char name;
    bool downloaded;
    bool invisible;
    bool firewall;
    bool reveal;
};

#endif
