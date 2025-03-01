from Repository.GroupsRepository import GroupsRepository as GroupsRepository
from Repository.RoomsRepository import RoomsRepository
from Repository.SubjectsRepository import SubjectsRepository
from Repository.TeachersRepository import TeachersRepository
from Repository.TimeTableRepo import TimeTableRepo
from services.CeleryService import *

def main():

    groups_repository = GroupsRepository()
    subjects_repository = SubjectsRepository()
    teachers_repository = TeachersRepository()
    rooms_repository = RoomsRepository()
    timetable_repo = TimeTableRepo()

    # generator = TimeTableGenerator(
    #     teachers_repository,
    #     subjects_repository,
    #     rooms_repository,
    #     groups_repository,
    #     timetable_repo,
    # )
    # generator.generate_timetable()
    generate_timetable(    teachers_repository,
        subjects_repository,
        rooms_repository,
        groups_repository,
        timetable_repo)
    timetable_repo.print_to_csv("result.csv")

if __name__ == "__main__":
    main()