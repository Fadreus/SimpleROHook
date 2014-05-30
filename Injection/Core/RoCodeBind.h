/*
    This file is part of SimpleROHook.

    SimpleROHook is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    SimpleROHook is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with SimpleROHook.  If not, see <http://www.gnu.org/licenses/>.
*/
#pragma once

#include "shared.h"

#include "PerformanceCounter.h"
#include "SearchCode.h"
#include "FastFont/SFastFont.h"

// Required to create a dll for jRO.
//#define JRO_CLIENT_STRUCTURE
//

#include "ro/system.h"
#include "ro/mouse.h"
#include "ro/unit.h"
#include "ro/res.h"
#include "ro/ui.h"
#include "ro/object.h"
#include "ro/map.h"
#include "ro/task.h"

#define D3DFVF_CPOLVERTEX (D3DFVF_XYZRHW|D3DFVF_DIFFUSE)
#define D3DCOLOR_ARGB(a,r,g,b) \
	((D3DCOLOR)((((a)&0xff)<<24)|(((r)&0xff)<<16)|(((g)&0xff)<<8)|((b)&0xff)))

struct CPOLVERTEX {
	FLOAT x, y, z, rhw; // The transformed position for the vertex
	DWORD color;        // The vertex color
};

typedef void (__cdecl *tPlayStream)(const char *streamFileName,int playflag);

class CRoCodeBind
{
private:
	CRenderer** g_renderer;
	CModeMgr *g_pmodeMgr;
	CMouse* g_mouse;

	tPlayStream m_funcRagexe_PlayStream;

	HWND m_hWnd;

#define PACKETQUEUE_BUFFERSIZE 40960
	char m_packetqueuebuffer[PACKETQUEUE_BUFFERSIZE];
	unsigned int m_packetqueue_head;

#define ROPACKET_MAXLEN 0x2000
	int m_packetLenMap_table[ROPACKET_MAXLEN];
	int m_packetLenMap_table_index;

#define MAX_FLLORSKILLTYPE 0x100
	DWORD m_M2ESkillColor[MAX_FLLORSKILLTYPE];

	struct p_std_map_packetlen
	{
		struct p_std_map_packetlen *left, *parent, *right;
		DWORD key;
		int value;
	};
	int GetTreeData(p_std_map_packetlen* node);

	void ProjectVertex(vector3d& src,matrix& vtm,float *x,float *y,float *oow);
	void ProjectVertex(vector3d& src,matrix& vtm,tlvertex3d *vert);

	void LoadIni(void);
	void SearchRagexeMemory(void);

	LPDIRECTDRAWSURFACE7 m_pddsFontTexture;
	CSFastFont *m_pSFastFont;

	struct MouseDataStructure
	{
		int x_axis,y_axis,wheel;
		char l_button,r_button,wheel_button,pad;
	};

public:
	CRoCodeBind() :
		m_hWnd(NULL),m_funcRagexe_PlayStream(NULL),
		m_packetLenMap_table_index(0),m_packetqueue_head(0),
		m_pSFastFont(NULL),m_pddsFontTexture(NULL),
		g_renderer(NULL),g_pmodeMgr(NULL),g_mouse(NULL)
	{};
	virtual ~CRoCodeBind();

	void Init(IDirect3DDevice7* d3ddevice);

	void DrawSRHDebug(IDirect3DDevice7* d3ddevice);
	void DrawOn3DMap(IDirect3DDevice7* d3ddevice);
	void DrawM2E(IDirect3DDevice7* d3ddevice);

	int GetPacketLength(int opcode);
	void PacketQueueProc(char *buf,int len);

	void InitWindowHandle(HWND hWnd){m_hWnd = hWnd;};

	void MouseProc(HRESULT Result,LPVOID lpvData,BOOL FreeMouse);
	void SetMouseCurPos(int x,int y);
};


extern BOOL g_FreeMouseSw;
extern StSHAREDMEMORY *g_pSharedData;

extern CRoCodeBind* g_pRoCodeBind;

BOOL OpenSharedMemory(void);
BOOL ReleaseSharedMemory(void);


extern CPerformanceCounter g_PerformanceCounter;



