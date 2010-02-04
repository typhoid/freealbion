/*
Copyright (C) 2010 Neil Ramsbottom

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

*/
#include "types.h"

#ifndef SYSTEXTS_H
#define SYSTEXTS_H

	#define ALBION_MAX_SYSTEXT		0xff

	typedef struct {
		uint16_t			id;
		uchar_t				*text;
		struct systext		*next;		/* next text in the list */
	} systext;


	int InitSysTexts();
	void FreeSysTexts();

	systext* SysTextById(uint16_t id);

#endif