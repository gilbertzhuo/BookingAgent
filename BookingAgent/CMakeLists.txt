cmake_minimum_required(VERSION 3.12)
project(Final)

set(CMAKE_CXX_STANDARD 14)

add_executable(Final main.cpp Ticket.h Constant.h FlightTicket.cpp FlightTicket.h HotelVoucher.cpp HotelVoucher.h EventTicket.cpp EventTicket.h ClientRequest.cpp ClientRequest.h Package.cpp Package.h RequestGenerator.cpp RequestGenerator.h TravelAgent.cpp TravelAgent.h SmartTravelAgent.cpp SmartTravelAgent.h)