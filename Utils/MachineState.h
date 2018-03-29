/*
 * MachineState.h
 *
 * Created: 22 2018 by Ashley
 *
 * Copyright 2018 Octronic. All rights reserved.
 *
 * This file may be distributed under the terms of GNU Public License version
 * 3 (GPL v3) as defined by the Free Software Foundation (FSF). A copy of the
 * license should have been included with this file, or the project in which
 * this file belongs to. You may also find the details of GPL v3 at:
 * http://www.gnu.org/licenses/gpl-3.0.txt
 *
 * If you have any questions regarding the use of this file, feel free to
 * contact the author of this file, or the owner of the project in which
 * this file belongs to.
 */

#pragma once

namespace Cocoanut
{
    enum MachineState
    {
        MACHINE_STATE_UNKNOWN,
        MACHINE_STATE_IDLE,
        MACHINE_STATE_ALARM,
        MACHINE_STATE_RUN,
        MACHINE_STATE_HOME,
        MACHINE_STATE_HOLD,
        MACHINE_STATE_QUEUE,
        MACHINE_STATE_CHECK,
        MACHINE_STATE_DOOR
    };
}