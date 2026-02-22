CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++20 -O2
TARGET = a.out
SRCS = main.cpp

# デフォルトターゲット（ただ make と打った時）
all: $(TARGET)

# コンパイル
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $< -o $@

# ★ここを追加：テスト実行
# $(TARGET) に依存しているので、変更があれば勝手にコンパイルしてからテストしてくれる
test: $(TARGET)
	oj t -c "./$(TARGET)"

# 実行（手動入力用）
run: $(TARGET)
	./$(TARGET)

# 掃除
clean:
	rm -f $(TARGET)
	rm -rf test
