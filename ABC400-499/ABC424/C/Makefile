# コンパイラ
CXX = g++

# コンパイルオプション (競技プログラミング向け)
CXXFLAGS = -Wall -Wextra -Werror -std=c++17 -O2

# 実行ファイル名 (ここではディレクトリ名ではなく、問題を解くプログラムという意味で 'a.out' にすることが多い)
TARGET = main

# ソースファイル
SRCS = main.cpp

# デフォルトターゲット: makeを実行した時に呼ばれる
all: $(TARGET)

# 実行ファイルを生成するルール
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $< -o $@

# 実行ファイルを実行するルール (make run で実行)
run: $(TARGET)
	./$(TARGET)

# コンパイルで生成されたファイルを削除する
clean:
	rm -f $(TARGET)