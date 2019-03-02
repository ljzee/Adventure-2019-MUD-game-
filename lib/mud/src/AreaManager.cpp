//
// Created by Vsevolod on 2019-03-01.
//

#include <boost/filesystem.hpp>
#include "AreaManager.h"
#include "JSONParser.h"

using namespace boost::filesystem;

AreaManager::AreaManager(const std::string& pathToJSONFolder) {
    JSONParser json;
    if(is_directory(pathToJSONFolder)) {
        std::cout << "Debug info. Check area population" << std::endl;
        for (auto &entry : boost::make_iterator_range(directory_iterator(pathToJSONFolder), {})) {
            Area area = json.generateArea(entry.path().string());
            areas.insert({area.getName(), area});
            std::cout << entry << "\n";
        }
    }
}
