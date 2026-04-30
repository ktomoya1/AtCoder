CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++23
TARGET = a.out
SRCS = main.cpp

# デフォルトターゲット（ただ make と打った時）
all: $(TARGET)

# コンパイル
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -O2 $< -o $@

# ★ここを追加：テスト実行
# $(TARGET) に依存しているので、変更があれば勝手にコンパイルしてからテストしてくれる
test: $(SRCS)
	$(CXX) $(CXXFLAGS) -O2 $< -o $(TARGET)
	oj t -c "./$(TARGET)"

lldb: $(SRCS)
	$(CXX) $(CXXFLAGS) -g -O0 $< -o $(TARGET)
	lldb ./$(TARGET)

debug: $(SRCS)
	$(CXX) $(CXXFLAGS) -g -O0 -fsanitize=address,undefined $< -o $(TARGET)
	MallocNanoZone=0 ./$(TARGET)

# 実行（手動入力用）
run: $(TARGET)
	./$(TARGET)

# 掃除
clean:
	rm -f $(TARGET)
	rm -rf test
