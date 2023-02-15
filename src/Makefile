#Copyright Team S69_MATH
#название либы
LIB = s_math.a
TEST_LIB = $(addprefix test_, $(LIB))
#Компилятор
CC = gcc
GCOV = gcov
#Изменение компилятора под gcc-12 на M1
ifeq ($(shell uname -p), arm)
		CC = gcc-12
		GCOV = gcov-12
endif

#Стандартные флаги
FLAGS = -Wall -Werror -Wextra -std=c11
#опциональные флаги
OPTFLAGS = -g -pedantic
#Флаги для меток для gcov
GFLAGS = -fprofile-arcs -ftest-coverage
#Подключение либ нужных
IN_FLAGS = $(shell pkg-config --cflags check)
CHFLAGS = $(shell pkg-config --cflags --libs check)
#Подключение gcov
GOFLAGS = -lgcov
#Директории где лежат тесты, и обьектные файлы, и gcov_report
TEST_DIR = tests
BUILD_DIR = build
BUILD_TEST_DIR = build_tests
TEST_BUILD_DIR = test_build
GCOV_DIR = gcov_report

#Чем открываем
OPENOS = vi
ifeq ($(shell uname -s), Linux)
		OPENOS = xdg-open
endif
ifeq ($(shell uname -s), Darwin)
		OPENOS = open
endif

# Файлы
s_SOURCES = $(wildcard s_*.c)
TESTS = $(wildcard $(TEST_DIR)/test_*.c)
s_OBJECTS=$(addprefix $(BUILD_DIR)/, $(s_SOURCES:.c=.o))
TEST_s_OBJECTS=$(addprefix $(TEST_BUILD_DIR)/, $(s_SOURCES:.c=.o))
TEST_OBJECTS=$(addprefix $(BUILD_TEST_DIR)/, $(notdir $(TESTS:.c=.o)))

# Игнорируемые стадии в качестве файлов
.PHONY : all clean gcov_report \
				style style-fix check  \
				rebuild docker gcov    \
				valgrind run external

# Компилируем либо, тесты, и делаем репорт в котором запуск
all : $(LIB) test gcov_report

# запуск теста
run :
	./test

###############################################
# ФОРМИРУЕМ И ЗАПУСКАЕМ ТЕСТЫ С ТЕСТ ЛИБОЙ
###############################################

#Важно чтоб либа была в конце самом!
test: $(TEST_OBJECTS) $(TEST_LIB)
	$(CC) $(FLAGS) $^ -o $@ $(CHFLAGS) $(GOFLAGS) -lm
## LM убрать (был для федоры, но вообще не должен быть)

#Компилируем все тесты, включая test который все соединяет воедино
$(TEST_OBJECTS) : $(BUILD_TEST_DIR)/%.o : $(TEST_DIR)/%.c $(TEST_DIR)/test_me.h
	@mkdir -p $(BUILD_TEST_DIR)
	$(CC) $(FLAGS) $(IN_FLAGS) -c $< -o $@

###############################################
# ФОРМИРОВАНИЕ ТЕСТОВОЙ ВЕРСИИ БИБЛИОТЕКИ
###############################################

#формируем тест либу
$(TEST_LIB): $(TEST_s_OBJECTS)
	ar -rcs $@ $^

#формируем обьектные файлы для тест библиотеки
$(TEST_s_OBJECTS): $(TEST_BUILD_DIR)/%.o : %.c $(LIB:.a=.h)
	@mkdir -p $(TEST_BUILD_DIR)
	$(CC) $(FLAGS) $(OPTFLAGS) $(GFLAGS) -c $< -o $@

###############################################
# ФОРМИРОВАНИЕ ПРОД ВЕРСИИ БИБЛИОТЕКИ
###############################################

#формируем либу
$(LIB): $(s_OBJECTS)
	ar -rcs $@ $^

#формируем обьектные файлы для библиотеки
$(s_OBJECTS): $(BUILD_DIR)/%.o : %.c $(LIB:.a=.h)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(FLAGS) -c $< -o $@

###############################################
# GCOV_REPORT
###############################################

# Открываем результат
gcov: gcov_report
	@$(OPENOS) ./$(GCOV_DIR)/gcov_report.html

#требуется по тз, но должен зависеть от файла, чтоб не пересобираться...
gcov_report : $(LIB) test run $(GCOV_DIR)/gcov_report.html

# Формирование отчета
$(GCOV_DIR)/gcov_report.html : $(LIB) test
	@mkdir -p gcov_report
	gcovr -r . --gcov-executable $(GCOV) --html --html-details -o $(GCOV_DIR)/gcov_report.html

###############################################
# ВСЯКИЕ ПРОВЕРКИ
###############################################

# утечки
valgrind: test
	valgrind --leak-check=full --show-leak-kinds=all \
	--track-origins=yes --verbose ./test

#стиль
style: 
	@cp ../materials/linters/.clang-format ./
	@echo =COPY DONE!=
	@clang-format -n *.c *.h
	@clang-format -n tests/*.c tests/*.h
	@echo =CHECK COMPLETED=
	@rm -rf .clang-format
	@echo =REMOVE DONE!=

#исправление стиля
style-fix: 
	@cp ../materials/linters/.clang-format ./
	@echo =COPY DONE!=
	@clang-format -i *.c *.h
	@clang-format -i tests/*.c tests/*.h
	@echo =CHECK COMPLETED=
	@rm -rf .clang-format
	@echo =REMOVE DONE!=

#cppcheck
check:
	cppcheck --enable=all --suppress=missingIncludeSystem ./

#запуск докера
docker: clean
	@cd ../materials/build && chmod +x ./run.sh && ./run.sh

###############################################
# ОЧИСТКА И ПЕРЕСБОРКА
###############################################

clean:
	@echo ==Cleaning...==
	@rm -rf $(GCOV_DIR) $(BUILD_DIR) $(BUILD_TEST_DIR) $(TEST_BUILD_DIR)
	@rm -rf *.html
	@rm -rf a.out test
	@rm -rf *.a
	@rm -rf *.css
	@rm -rf *.gch $(TEST_DIR)/*.gch
	@rm -rf ./external/external
	@echo ==EVERYTHING REMOVED!==
	@echo ==Done!==

rebuild : 
	$(MAKE) clean
	$(MAKE) all
