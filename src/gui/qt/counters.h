/*  LOOT

    A load order optimisation tool for
    Morrowind, Oblivion, Skyrim, Skyrim Special Edition, Skyrim VR,
    Fallout 3, Fallout: New Vegas, Fallout 4 and Fallout 4 VR.

    Copyright (C) 2021    Oliver Hamlet

    This file is part of LOOT.

    LOOT is free software: you can redistribute
    it and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation, either version 3 of
    the License, or (at your option) any later version.

    LOOT is distributed in the hope that it will
    be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with LOOT.  If not, see
    <https://www.gnu.org/licenses/>.
    */

#ifndef LOOT_GUI_QT_COUNTERS
#define LOOT_GUI_QT_COUNTERS

#include <loot/struct/simple_message.h>

#include "gui/plugin_item.h"
#include "gui/qt/filters_states.h"

namespace loot {
struct GeneralInformationCounters {
  GeneralInformationCounters() = default;
  GeneralInformationCounters(const std::vector<SimpleMessage>& generalMessages,
                             const std::vector<PluginItem>& plugins);

  size_t warnings{0};
  size_t errors{0};
  size_t totalMessages{0};

  size_t activeLight{0};
  size_t activeRegular{0};
  size_t dirty{0};
  size_t totalPlugins{0};

private:
  void countMessages(const std::vector<SimpleMessage>& messages);
};

size_t countHiddenMessages(const std::vector<PluginItem>& plugins,
                           const CardContentFiltersState& filters);
}

Q_DECLARE_METATYPE(loot::GeneralInformationCounters);

#endif
