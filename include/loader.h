/*
 *  Copyright (C) 2016  The BoxedWine Team
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#ifndef __LOADER_H__
#define __LOADER_H__

class KProcess;
class KThread;
class FsOpenNode;

class ElfLoader {
public:
    static bool loadProgram(KProcess* process, FsOpenNode* openNode, U32* eip);
    static FsOpenNode* inspectNode(KProcess* process, const std::string& currentDirectory, const BoxedPtr<FsNode>& node, std::string& loader, std::string& interpreter, std::vector<std::string>& interpreterArgs);
    static int getMemSizeOfElf(FsOpenNode* openNode);
    static U32 getPELoadAddress(FsOpenNode* FsopenNode, U32* section, U32* numberOfSections, U32* sizeOfSection);

private:
    static std::string getInterpreter(FsOpenNode* openNode, bool* isElf);
};

#endif