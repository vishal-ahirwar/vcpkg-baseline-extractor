add_executable(baseline src/main.cpp)# Add your Source Files here
target_link_libraries(baseline PRIVATE Boost::process)
target_link_libraries(baseline PRIVATE cpr::cpr)
target_link_libraries(baseline PRIVATE 7zip::7zip)
message(STATUS "Boost include dir: ${Boost_INCLUDE_DIRS}")
message(STATUS "Boost libraries: ${Boost_LIBRARIES}")