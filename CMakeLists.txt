cmake_minimum_required(VERSION 3.23)
project(budget_tracker LANGUAGES C)

add_executable(budget_tracker)

target_sources(budget_tracker
  PRIVATE
    src/main.c
)
