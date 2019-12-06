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

SSE_RR(addpsXmm)
SSE_RE(addpsE128)
SSE_RR(addssXmm)
SSE_RE(addssE32)
SSE_RR(subpsXmm)
SSE_RE(subpsE128)
SSE_RR(subssXmm)
SSE_RE(subssE32)
SSE_RR(mulpsXmm)
SSE_RE(mulpsE128)
SSE_RR(mulssXmm)
SSE_RE(mulssE32)
SSE_RR(divpsXmm)
SSE_RE(divpsE128)
SSE_RR(divssXmm)
SSE_RE(divssE32)
SSE_RR(rcppsXmm)
SSE_RE(rcppsE128)
SSE_RR(rcpssXmm)
SSE_RE(rcpssE32)
SSE_RR(sqrtpsXmm)
SSE_RE(sqrtpsE128)
SSE_RR(sqrtssXmm)
SSE_RE(sqrtssE32)
SSE_RR(rsqrtpsXmm)
SSE_RE(rsqrtpsE128)
SSE_RR(rsqrtssXmm)
SSE_RE(rsqrtssE32)
SSE_RR(maxpsXmm)
SSE_RE(maxpsE128)
SSE_RR(maxssXmm)
SSE_RE(maxssE32)
SSE_RR(minpsXmm)
SSE_RE(minpsE128)
SSE_RR(minssXmm)
SSE_RE(minssE32)
SSE_RR(pavgbMmxMmx)
SSE_RE(pavgbMmxE64)
SSE_RR(pavgwMmxMmx)
SSE_RE(pavgwMmxE64)
SSE_RR(psadbwMmxMmx)
SSE_RE(psadbwMmxE64)
SSE_RR_I8(pextrwR32Mmx)
SSE_RE_I8(pextrwE16Mmx)
SSE_RR_I8(pinsrwMmxR32)
SSE_RE_I8(pinsrwMmxE16)
SSE_RR(pmaxswMmxMmx)
SSE_RE(pmaxswMmxE64)
SSE_RR(pmaxubMmxMmx)
SSE_RE(pmaxubMmxE64)
SSE_RR(pminswMmxMmx)
SSE_RE(pminswMmxE64)
SSE_RR(pminubMmxMmx)
SSE_RE(pminubMmxE64)
SSE_RR(pmovmskbR32Mmx)
SSE_RR(pmulhuwMmxMmx)
SSE_RE(pmulhuwMmxE64)
SSE_RR_I8(pshufwMmxMmx)
SSE_RE_I8(pshufwMmxE64)
SSE_RR(andnpsXmmXmm)
SSE_RE(andnpsXmmE128)
SSE_RR(andpsXmmXmm)
SSE_RE(andpsXmmE128)
SSE_RR(orpsXmmXmm)
SSE_RE(orpsXmmE128)
SSE_RR(xorpsXmmXmm)
SSE_RE(xorpsXmmE128)
SSE_RR(cvtpi2psXmmMmx)
SSE_RE(cvtpi2psXmmE64)
SSE_RR(cvtps2piMmxXmm)
SSE_RE(cvtps2piMmxE64)
SSE_RR(cvtsi2ssXmmR32)
SSE_RE(cvtsi2ssXmmE32)
SSE_RR(cvtss2siR32Xmm)
SSE_RE(cvtss2siR32E32)
SSE_RR(cvttps2piMmxXmm)
SSE_RE(cvttps2piMmxE64)
SSE_RR(cvttss2siR32Xmm)
SSE_RE(cvttss2siR32E32)
SSE_RR(movapsXmmXmm)
SSE_RE(movapsXmmE128)
SSE_RE(movapsE128Xmm)
SSE_RR(movhlpsXmmXmm)
SSE_RR(movlhpsXmmXmm)
SSE_RE(movhpsXmmE64)
SSE_RE(movhpsE64Xmm)
SSE_RE(movlpsXmmE64)
SSE_RE(movlpsE64Xmm)
SSE_RR(movmskpsR32Xmm)
SSE_RR(movssXmmXmm)
SSE_RE(movssXmmE32)
SSE_RE(movssE32Xmm)
SSE_RR(movupsXmmXmm)
SSE_RE(movupsXmmE128)
SSE_RE(movupsE128Xmm)
SSE_RR_EDI(maskmovqEDIMmxMmx)
SSE_RE(movntpsE128Xmm)
SSE_RE(movntqE64Mmx)
SSE_RR_I8(shufpsXmmXmm)
SSE_RE_I8(shufpsXmmE128)
SSE_RR(unpckhpsXmmXmm)
SSE_RE(unpckhpsXmmE128)
SSE_RR(unpcklpsXmmXmm)
SSE_RE(unpcklpsXmmE128)
SSE_0(prefetchT0)
SSE_0(prefetchT1)
SSE_0(prefetchT2)
SSE_0(prefetchNTA)
SSE_RR_I8(cmppsXmmXmm)
SSE_RE_I8(cmppsXmmE128)
SSE_RR_I8(cmpssXmmXmm)
SSE_RE_I8(cmpssXmmE32)
SSE_RR(comissXmmXmm)
SSE_RE(comissXmmE32)
SSE_RR(ucomissXmmXmm)
SSE_RE(ucomissXmmE32)
SSE_RE(stmxcsr)
SSE_RE(ldmxcsr)