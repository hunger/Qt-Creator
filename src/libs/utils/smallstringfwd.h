/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of Qt Creator.
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 as published by the Free Software
** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
****************************************************************************/

#pragma once

#if __cplusplus >= 201703L
#define constexpr17 constexpr
#else
#define constexpr17 inline
#endif

#if __cplusplus >= 202002L
#define constexpr20 constexpr
#else
#define constexpr20 inline
#endif

using uint = unsigned int;

namespace Utils {

class SmallStringView;
template <uint Size>
class BasicSmallString;
using SmallString = BasicSmallString<31>;
using PathString = BasicSmallString<190>;

} // namespace Utils
