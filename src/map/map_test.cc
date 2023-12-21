#include <gtest/gtest.h>

#include <map>
#include <string>

#include "../containers.h"

TEST(TestMapMapСonstructor, DefaultConstructor) {
  containers::Map<int, int> m;
  std::map<int, int> m2;
  ASSERT_EQ(m.size(), m2.size());
}

TEST(TestMapСonstructor, InitializerListConstructor) {
  containers::Map<int, int> m{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  std::map<int, int> m2{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  ASSERT_EQ(m[1], m2[1]);
  ASSERT_EQ(m[-3], m2[-3]);
  ASSERT_EQ(m[6], m2[6]);
  ASSERT_EQ(m[4], m2[4]);
}

TEST(TestMapСonstructor, InitializerListConstructorSecond) {
  containers::Map<int, int> m{{1, 10}, {-3, 20}, {6, 30},  {4, 40},
                              {3, 50}, {-1, 60}, {-10, 70}};
  std::map<int, int> m2{{1, 10}, {-3, 20}, {6, 30},  {4, 40},
                        {3, 50}, {-1, 60}, {-10, 70}};
  ASSERT_EQ(m[1], m2[1]);
  ASSERT_EQ(m[-3], m2[-3]);
  ASSERT_EQ(m[6], m2[6]);
  ASSERT_EQ(m[4], m2[4]);
  ASSERT_EQ(m[3], m2[3]);
  ASSERT_EQ(m[-10], m2[-10]);
  ASSERT_EQ(m[3], m2[3]);
  ASSERT_EQ(m[-1], m2[-1]);
}

TEST(TestMapСonstructor, InitializerListConstructorThird) {
  containers::Map<std::string, int> m{{"this", 1}, {"sentence", 2},
                                      {"is", 3},   {"not", 4},
                                      {"a", 5},    {"word", 6}};
  std::map<std::string, int> m2{{"this", 1}, {"sentence", 2}, {"is", 3},
                                {"not", 4},  {"a", 5},        {"word", 6}};
  ASSERT_EQ(m["this"], m2["this"]);
  ASSERT_EQ(m["sentence"], m2["sentence"]);
  ASSERT_EQ(m["is"], m2["is"]);
  ASSERT_EQ(m["not"], m2["not"]);
  ASSERT_EQ(m["a"], m2["a"]);
  ASSERT_EQ(m["word"], m2["word"]);
}

TEST(TestMapСonstructor, CopyConstructor) {
  containers::Map<int, int> m{{1, 10}, {-3, 100}, {6, 100}, {4, 50}};
  containers::Map<int, int> m3(m);
  std::map<int, int> m2{{1, 10}, {-3, 100}, {6, 100}, {4, 50}};
  std::map<int, int> m4(m2);
  ASSERT_EQ(m3[1], m4[1]);
  ASSERT_EQ(m3[-3], m4[-3]);
  ASSERT_EQ(m3[6], m4[6]);
  ASSERT_EQ(m3[4], m4[4]);
  ASSERT_EQ(m3[3], m4[3]);
}

TEST(TestMapСonstructor, CopyConstructorSecond) {
  containers::Map<int, int> m{{1, 10}, {-3, 20}, {6, 30},  {4, 40},
                              {3, 50}, {-1, 60}, {-10, 70}};
  std::map<int, int> m2{{1, 10}, {-3, 20}, {6, 30},  {4, 40},
                        {3, 50}, {-1, 60}, {-10, 70}};
  containers::Map<int, int> m3(m);
  std::map<int, int> m4(m2);
  ASSERT_EQ(m3[1], m4[1]);
  ASSERT_EQ(m3[-3], m4[-3]);
  ASSERT_EQ(m3[6], m4[6]);
  ASSERT_EQ(m3[4], m4[4]);
  ASSERT_EQ(m3[3], m4[3]);
  ASSERT_EQ(m3[-10], m4[-10]);
  ASSERT_EQ(m3[3], m4[3]);
  ASSERT_EQ(m3[-1], m4[-1]);
}

TEST(TestMapСonstructor, CopyConstructorThird) {
  containers::Map<std::string, int> m{{"this", 1}, {"sentence", 2},
                                      {"is", 3},   {"not", 4},
                                      {"a", 5},    {"word", 6}};
  std::map<std::string, int> m2{{"this", 1}, {"sentence", 2}, {"is", 3},
                                {"not", 4},  {"a", 5},        {"word", 6}};
  containers::Map<std::string, int> m3(m);
  std::map<std::string, int> m4(m2);
  ASSERT_EQ(m3["this"], m4["this"]);
  ASSERT_EQ(m3["sentence"], m4["sentence"]);
  ASSERT_EQ(m3["is"], m4["is"]);
  ASSERT_EQ(m3["not"], m4["not"]);
  ASSERT_EQ(m3["a"], m4["a"]);
  ASSERT_EQ(m3["word"], m4["word"]);
}

TEST(TestMapСonstructor, MoveConstructor) {
  containers::Map<int, int> m{{1, 10}, {-3, 100}, {6, 100}, {4, 50}};
  containers::Map<int, int> m3(std::move(m));
  std::map<int, int> m2{{1, 10}, {-3, 100}, {6, 100}, {4, 50}};
  std::map<int, int> m4(std::move(m2));
  ASSERT_EQ(m3[1], m4[1]);
  ASSERT_EQ(m3[-3], m4[-3]);
  ASSERT_EQ(m3[6], m4[6]);
  ASSERT_EQ(m3[4], m4[4]);
}

TEST(TestMapСonstructor, MoveConstructorSecond) {
  containers::Map<int, int> m{{1, 10}, {-3, 20}, {6, 30},  {4, 40},
                              {3, 50}, {-1, 60}, {-10, 70}};
  std::map<int, int> m2{{1, 10}, {-3, 20}, {6, 30},  {4, 40},
                        {3, 50}, {-1, 60}, {-10, 70}};
  containers::Map<int, int> m3(std::move(m));
  std::map<int, int> m4(std::move(m2));
  ASSERT_EQ(m3[1], m4[1]);
  ASSERT_EQ(m3[-3], m4[-3]);
  ASSERT_EQ(m3[6], m4[6]);
  ASSERT_EQ(m3[4], m4[4]);
  ASSERT_EQ(m3[3], m4[3]);
  ASSERT_EQ(m3[-10], m4[-10]);
  ASSERT_EQ(m3[3], m4[3]);
  ASSERT_EQ(m3[-1], m4[-1]);
}

TEST(TestMapСonstructor, MoveConstructorThird) {
  containers::Map<std::string, int> m{{"this", 1}, {"sentence", 2},
                                      {"is", 3},   {"not", 4},
                                      {"a", 5},    {"word", 6}};
  std::map<std::string, int> m2{{"this", 1}, {"sentence", 2}, {"is", 3},
                                {"not", 4},  {"a", 5},        {"word", 6}};
  containers::Map<std::string, int> m3(std::move(m));
  std::map<std::string, int> m4(std::move(m2));
  ASSERT_EQ(m3["this"], m4["this"]);
  ASSERT_EQ(m3["sentence"], m4["sentence"]);
  ASSERT_EQ(m3["is"], m4["is"]);
  ASSERT_EQ(m3["not"], m4["not"]);
  ASSERT_EQ(m3["a"], m4["a"]);
  ASSERT_EQ(m3["word"], m4["word"]);
}

TEST(TestMapOperator, OperatorFirst) {
  containers::Map<int, int> m{{1, 10}, {-3, 100}, {6, 100}, {4, 50}};
  containers::Map<int, int> m3 = m;
  std::map<int, int> m2{{1, 10}, {-3, 100}, {6, 100}, {4, 50}};
  std::map<int, int> m4 = m2;
  ASSERT_EQ(m3[1], m4[1]);
  ASSERT_EQ(m3[-3], m4[-3]);
  ASSERT_EQ(m3[6], m4[6]);
  ASSERT_EQ(m3[4], m4[4]);
}

TEST(TestMapOperator, OperatorSecond) {
  containers::Map<std::string, int> m{{"this", 1}, {"sentence", 2},
                                      {"is", 3},   {"not", 4},
                                      {"a", 5},    {"word", 6}};
  std::map<std::string, int> m2{{"this", 1}, {"sentence", 2}, {"is", 3},
                                {"not", 4},  {"a", 5},        {"word", 6}};
  containers::Map<std::string, int> m3 = m;
  std::map<std::string, int> m4 = m2;
  ASSERT_EQ(m3["this"], m4["this"]);
  ASSERT_EQ(m3["sentence"], m4["sentence"]);
  ASSERT_EQ(m3["is"], m4["is"]);
  ASSERT_EQ(m3["not"], m4["not"]);
  ASSERT_EQ(m3["a"], m4["a"]);
  ASSERT_EQ(m3["word"], m4["word"]);
}

TEST(TestMapOperator, OperatorThird) {
  containers::Map<int, int> m{{1, 10}, {-3, 100}, {6, 100}, {4, 50}};
  containers::Map<int, int> m3 = std::move(m);
  std::map<int, int> m2{{1, 10}, {-3, 100}, {6, 100}, {4, 50}};
  std::map<int, int> m4 = std::move(m2);
  ASSERT_EQ(m3[1], m4[1]);
  ASSERT_EQ(m3[-3], m4[-3]);
  ASSERT_EQ(m3[6], m4[6]);
  ASSERT_EQ(m3[4], m4[4]);
}

TEST(TestMapOperator, OperatorFourth) {
  containers::Map<std::string, int> m{{"this", 1}, {"sentence", 2},
                                      {"is", 3},   {"not", 4},
                                      {"a", 5},    {"word", 6}};
  std::map<std::string, int> m2{{"this", 1}, {"sentence", 2}, {"is", 3},
                                {"not", 4},  {"a", 5},        {"word", 6}};
  containers::Map<std::string, int> m3 = std::move(m);
  std::map<std::string, int> m4 = std::move(m2);
  ASSERT_EQ(m3["this"], m4["this"]);
  ASSERT_EQ(m3["sentence"], m4["sentence"]);
  ASSERT_EQ(m3["is"], m4["is"]);
  ASSERT_EQ(m3["not"], m4["not"]);
  ASSERT_EQ(m3["a"], m4["a"]);
  ASSERT_EQ(m3["word"], m4["word"]);
}

TEST(TestMapSize, SizeFirst) {
  containers::Map<int, int> m{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  std::map<int, int> m2{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  ASSERT_EQ(m.size(), m2.size());
}

TEST(TestMapSize, SizeSecond) {
  containers::Map<int, int> m;
  std::map<int, int> m2;
  ASSERT_EQ(m.size(), m2.size());
}

TEST(TestMapMaxSize, MaxSizeFirst) {
  containers::Map<int, int> m{{1, 100}, {-3, 100}, {6, 100}};
  std::map<int, int> m2{{1, 100}, {-3, 100}, {6, 100}};
  ASSERT_EQ(m.max_size(), m2.max_size());
}

TEST(TestMapMaxSize, MaxSizeSecond) {
  containers::Map<int, int> m;
  std::map<int, int> m2;
  ASSERT_EQ(m.max_size(), m2.max_size());
}

TEST(TestMapMaxSize, MaxSizeThird) {
  containers::Map<char, int> m{{'t', 1}, {'s', 2}, {'i', 3},
                               {'n', 4}, {'a', 5}, {'w', 6}};
  std::map<char, int> m2{{'t', 1}, {'s', 2}, {'i', 3},
                         {'n', 4}, {'a', 5}, {'w', 6}};
  ASSERT_EQ(m.max_size(), m2.max_size());
}

TEST(TestMapClear, ClearFirst) {
  containers::Map<int, int> m{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  std::map<int, int> m2{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  m.clear();
  m2.clear();
  ASSERT_EQ(m.size(), m2.size());
}

TEST(TestMapClear, ClearSecond) {
  containers::Map<int, int> m{
      {1, 100}, {-3, 100}, {6, 100}, {4, 50}, {-12, 45}};
  std::map<int, int> m2{{1, 100}, {-3, 100}, {6, 100}, {4, 50}, {-12, 45}};
  m.clear();
  m2.clear();
  ASSERT_EQ(m.size(), m2.size());
}

TEST(TestMapClear, ClearThird) {
  containers::Map<int, int> m;
  std::map<int, int> m2;
  m.clear();
  m2.clear();
  ASSERT_EQ(m.size(), m2.size());
}

TEST(TestMapEmpty, EmptyFirst) {
  containers::Map<int, int> m{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  std::map<int, int> m2{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  ASSERT_EQ(m.empty(), m2.empty());
}

TEST(TestMapEmpty, EmptySecond) {
  containers::Map<int, int> m;
  std::map<int, int> m2;
  ASSERT_EQ(m.empty(), m2.empty());
}

TEST(TestMapContains, ContainsFirst) {
  containers::Map<int, int> m{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  ASSERT_EQ(m.contains(1), true);
  ASSERT_EQ(m.contains(-3), true);
  ASSERT_EQ(m.contains(6), true);
  ASSERT_EQ(m.contains(4), true);
}

TEST(TestMapContains, ContainsSecond) {
  containers::Map<int, int> m;
  ASSERT_EQ(m.contains(10), false);
  ASSERT_EQ(m.contains(-8), false);
}

TEST(TestMapIterator, IteratorFirst) {
  containers::Map<int, int> m{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  std::map<int, int> m2{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  auto it = m.begin();
  auto i = m2.begin();
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
}

TEST(TestMapIterator, IteratorSecond) {
  containers::Map<int, int> m{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  std::map<int, int> m2{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  auto it = m.begin();
  auto i = m2.begin();
  it++;
  i++;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
}

TEST(TestMapIterator, IteratorThird) {
  containers::Map<int, int> m{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  std::map<int, int> m2{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  auto it = m.end();
  auto i = m2.end();
  --it;
  --i;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
}

TEST(TestMapIterator, IteratorFourth) {
  containers::Map<int, int> m = {{20, 4}};
  auto it = m.begin();
  it++;
  ASSERT_EQ((*it).first, 0);
}

TEST(TestMapIterator, IteratorFifth) {
  containers::Map<std::string, int> m{{"this", 1}, {"sentence", 2},
                                      {"is", 3},   {"not", 4},
                                      {"a", 5},    {"word", 6}};
  std::map<std::string, int> m2{{"this", 1}, {"sentence", 2}, {"is", 3},
                                {"not", 4},  {"a", 5},        {"word", 6}};
  auto it = m.end();
  auto i = m2.end();
  --it;
  --it;
  --it;
  --i;
  --i;
  --i;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
}

TEST(TestMapIterator, IteratorSixth) {
  containers::Map<int, int> m = {
      {20, 4}, {10, 3}, {4, 3},  {2, 2},  {5, 2},  {16, 3}, {3, 1},  {14, 2},
      {17, 2}, {12, 2}, {15, 2}, {11, 1}, {19, 1}, {25, 3}, {23, 2}, {30, 2}};
  std::map<int, int> m2 = {{20, 4}, {10, 3}, {4, 3},  {2, 2},  {5, 2},  {16, 3},
                           {3, 1},  {14, 2}, {17, 2}, {12, 2}, {15, 2}, {11, 1},
                           {19, 1}, {25, 3}, {23, 2}, {30, 2}};
  auto it = m.begin();
  auto i = m2.begin();
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it++;
  i++;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it++;
  i++;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it++;
  i++;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it++;
  i++;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it++;
  i++;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it++;
  i++;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it++;
  i++;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it++;
  i++;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it++;
  i++;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it++;
  i++;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it++;
  i++;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
}

TEST(TestMapIterator, IteratorSeventh) {
  containers::Map<int, int> m = {
      {20, 4}, {10, 3}, {4, 3},  {2, 2},  {5, 2},  {16, 3}, {3, 1},  {14, 2},
      {17, 2}, {12, 2}, {15, 2}, {11, 1}, {19, 1}, {25, 3}, {23, 2}, {30, 2}};
  std::map<int, int> m2 = {{20, 4}, {10, 3}, {4, 3},  {2, 2},  {5, 2},  {16, 3},
                           {3, 1},  {14, 2}, {17, 2}, {12, 2}, {15, 2}, {11, 1},
                           {19, 1}, {25, 3}, {23, 2}, {30, 2}};
  auto it = m.end();
  auto i = m2.end();
  it--;
  i--;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it--;
  i--;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it--;
  i--;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it--;
  i--;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it--;
  i--;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it--;
  i--;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it--;
  i--;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it--;
  i--;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it--;
  i--;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it--;
  i--;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it--;
  i--;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
}

TEST(TestMapConstIterator, ConstIteratorFirst) {
  containers::Map<int, int> m{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  std::map<int, int> m2{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  auto it = m.cbegin();
  auto i = m2.cbegin();
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
}

TEST(TestMapConstIterator, ConstIteratorSecond) {
  containers::Map<int, int> m{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  std::map<int, int> m2{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  auto it = m.cbegin();
  auto i = m2.cbegin();
  it++;
  i++;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
}

TEST(TestMapIteratorConst, IteratorThird) {
  containers::Map<int, int> m{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  std::map<int, int> m2{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  auto it = m.cend();
  auto i = m2.cend();
  --it;
  --i;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
}

TEST(TestMapIteratorConst, IteratorConstFourth) {
  containers::Map<int, int> m = {{20, 4}};
  auto it = m.cbegin();
  it++;
  ASSERT_EQ((*it).first, 0);
}

TEST(TestMapIteratorConst, IteratorConstFifth) {
  containers::Map<std::string, int> m{{"this", 1}, {"sentence", 2},
                                      {"is", 3},   {"not", 4},
                                      {"a", 5},    {"word", 6}};
  std::map<std::string, int> m2{{"this", 1}, {"sentence", 2}, {"is", 3},
                                {"not", 4},  {"a", 5},        {"word", 6}};
  auto it = m.cend();
  auto i = m2.cend();
  --it;
  --it;
  --it;
  --i;
  --i;
  --i;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
}

TEST(TestMapConstIterator, IteratorConstSixth) {
  containers::Map<int, int> m = {
      {20, 4}, {10, 3}, {4, 3},  {2, 2},  {5, 2},  {16, 3}, {3, 1},  {14, 2},
      {17, 2}, {12, 2}, {15, 2}, {11, 1}, {19, 1}, {25, 3}, {23, 2}, {30, 2}};
  std::map<int, int> m2 = {{20, 4}, {10, 3}, {4, 3},  {2, 2},  {5, 2},  {16, 3},
                           {3, 1},  {14, 2}, {17, 2}, {12, 2}, {15, 2}, {11, 1},
                           {19, 1}, {25, 3}, {23, 2}, {30, 2}};
  auto it = m.cbegin();
  auto i = m2.cbegin();
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it++;
  i++;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it++;
  i++;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it++;
  i++;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it++;
  i++;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it++;
  i++;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it++;
  i++;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it++;
  i++;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it++;
  i++;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it++;
  i++;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it++;
  i++;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it++;
  i++;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
}

TEST(TestMapConstIterator, IteratorConstSeventh) {
  containers::Map<int, int> m = {
      {20, 4}, {10, 3}, {4, 3},  {2, 2},  {5, 2},  {16, 3}, {3, 1},  {14, 2},
      {17, 2}, {12, 2}, {15, 2}, {11, 1}, {19, 1}, {25, 3}, {23, 2}, {30, 2}};
  std::map<int, int> m2 = {{20, 4}, {10, 3}, {4, 3},  {2, 2},  {5, 2},  {16, 3},
                           {3, 1},  {14, 2}, {17, 2}, {12, 2}, {15, 2}, {11, 1},
                           {19, 1}, {25, 3}, {23, 2}, {30, 2}};
  auto it = m.cend();
  auto i = m2.cend();
  it--;
  i--;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it--;
  i--;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it--;
  i--;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it--;
  i--;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it--;
  i--;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it--;
  i--;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it--;
  i--;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it--;
  i--;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it--;
  i--;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it--;
  i--;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
  it--;
  i--;
  ASSERT_EQ((*it).first, (*i).first);
  ASSERT_EQ((*it).second, (*i).second);
}

TEST(TestMapIterator, IteratorOperatorFirst) {
  containers::Map<int, int> m{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  std::map<int, int> m2{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  auto it = m.begin();
  auto it2 = m.begin();
  auto i = m2.begin();
  auto i2 = m2.begin();
  bool result1 = ((*it).first == (*it2).first);
  bool result2 = (i->first == i2->first);
  ASSERT_EQ(result1, result2);
}

TEST(TestMapIterator, IteratorOperatorSecond) {
  containers::Map<int, int> m{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  std::map<int, int> m2{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  auto it = m.begin();
  it++;
  auto it2 = m.begin();
  auto i = m2.begin();
  i++;
  auto i2 = m2.begin();
  bool result1 = ((*it).first == (*it2).first);
  bool result2 = (i->first == i2->first);
  ASSERT_EQ(result1, result2);
}

TEST(TestMapIterator, IteratorOperatorThird) {
  containers::Map<int, int> m{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  std::map<int, int> m2{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  auto it = m.begin();
  auto it2 = m.begin();
  auto i = m2.begin();
  auto i2 = m2.begin();
  bool result1 = ((*it).first != (*it2).first);
  bool result2 = (i->first != i2->first);
  ASSERT_EQ(result1, result2);
}

TEST(TestMapIterator, IteratorOperatorFourth) {
  containers::Map<int, int> m{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  std::map<int, int> m2{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  auto it = m.begin();
  it++;
  auto it2 = m.begin();
  auto i = m2.begin();
  i++;
  auto i2 = m2.begin();
  bool result1 = ((*it).first != (*it2).first);
  bool result2 = (i->first != i2->first);
  ASSERT_EQ(result1, result2);
}

TEST(TestMapIterator, IteratorOperatorFifth) {
  containers::Map<int, int> m{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  std::map<int, int> m2{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  auto it = m.begin();
  it++;
  auto it2 = m.begin();
  auto i = m2.begin();
  i++;
  auto i2 = m2.begin();
  bool result1 = ((*it).first != (*it2).first);
  bool result2 = (i->first != i2->first);
  ASSERT_EQ(result1, result2);
}

TEST(TestMapIterator, IteratorOperatorSixth) {
  containers::Map<int, int> m{{5, 40}, {-33, 12}};
  std::map<int, int> m2{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  auto it = m.begin();
  it++;
  auto i = m2.begin();
  i++;
  bool result1 = ((*it).first != (*i).first);
  ASSERT_EQ(result1, true);
}

TEST(TestMapIterator, IteratorOperatorSeventh) {
  containers::Map<int, int> m{{5, 40}, {-33, 12}};
  std::map<int, int> m2{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  auto it = m.begin();
  auto i = m2.begin();
  bool result1 = ((*it).first == (*i).first);
  ASSERT_EQ(result1, false);
}

TEST(TestMapIterator, IteratorOperatorEighth) {
  containers::Map<int, int> m{{5, 40}, {-33, 12}};
  std::map<int, int> m2{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  auto it = m.begin();
  it++;
  auto i = m2.begin();
  i++;
  bool result1 = ((*it).first != (*i).first);
  ASSERT_EQ(result1, true);
}

TEST(TestMapIterator, IteratorOperatorNinth) {
  containers::Map<int, int> m = {{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  std::map<int, int> m2 = {{5, 40}, {-33, 12}};
  auto it = m.begin();
  auto i = m2.begin();
  bool result1 = ((*it).first == (*i).first);
  ASSERT_EQ(result1, false);
}

TEST(TestMapConstIterator, ConstIteratorOperatorFirst) {
  containers::Map<int, int> m{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  std::map<int, int> m2{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  auto it = m.cbegin();
  auto it2 = m.cbegin();
  auto i = m2.cbegin();
  auto i2 = m2.cbegin();
  bool result1 = ((*it).first == (*it2).first);
  bool result2 = (i->first == i2->first);
  ASSERT_EQ(result1, result2);
}

TEST(TestMapConstIterator, IteratorConstOperatorSecond) {
  containers::Map<int, int> m{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  std::map<int, int> m2{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  auto it = m.cbegin();
  it++;
  auto it2 = m.cbegin();
  auto i = m2.cbegin();
  i++;
  auto i2 = m2.cbegin();
  bool result1 = ((*it).first == (*it2).first);
  bool result2 = (i->first == i2->first);
  ASSERT_EQ(result1, result2);
}

TEST(TestMapConstIterator, IteratorConstOperatorThird) {
  containers::Map<int, int> m{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  std::map<int, int> m2{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  auto it = m.cbegin();
  auto it2 = m.cbegin();
  auto i = m2.cbegin();
  auto i2 = m2.cbegin();
  bool result1 = ((*it).first != (*it2).first);
  bool result2 = (i->first != i2->first);
  ASSERT_EQ(result1, result2);
}

TEST(TestMapConstIterator, IteratorConstOperatorFourth) {
  containers::Map<int, int> m{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  std::map<int, int> m2{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  auto it = m.cbegin();
  it++;
  auto it2 = m.cbegin();
  auto i = m2.cbegin();
  i++;
  auto i2 = m2.cbegin();
  bool result1 = ((*it).first != (*it2).first);
  bool result2 = (i->first != i2->first);
  ASSERT_EQ(result1, result2);
}

TEST(TestMapConstIterator, IteratorConstOperatorSixth) {
  containers::Map<int, int> m{{5, 40}, {-33, 12}};
  std::map<int, int> m2{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  auto it = m.cbegin();
  it++;
  auto i = m2.cbegin();
  i++;
  bool result1 = ((*it).first != (*i).first);
  ASSERT_EQ(result1, true);
}

TEST(TestMapConstIterator, IteratorConstOperatorSeventh) {
  containers::Map<int, int> m{{5, 40}, {-33, 12}};
  std::map<int, int> m2{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  auto it = m.cbegin();
  auto i = m2.cbegin();
  bool result1 = ((*it).first == (*i).first);
  ASSERT_EQ(result1, false);
}

TEST(TestMapConstIterator, IteratorConstOperatorEighth) {
  containers::Map<int, int> m{{5, 40}, {-33, 12}};
  std::map<int, int> m2{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  auto it = m.cbegin();
  it++;
  auto i = m2.cbegin();
  i++;
  bool result1 = ((*it).first != (*i).first);
  ASSERT_EQ(result1, true);
}

TEST(TestMapConstIterator, IteratorConstOperatorNinth) {
  containers::Map<int, int> m = {{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  std::map<int, int> m2 = {{5, 40}, {-33, 12}};
  auto it = m.cbegin();
  auto i = m2.cbegin();
  bool result1 = ((*it).first == (*i).first);
  ASSERT_EQ(result1, false);
}

TEST(TestMapSwap, SwapFirst) {
  containers::Map<int, int> m{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  std::map<int, int> m2{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  containers::Map<int, int> m3{{2, 40}, {-4, 23}};
  std::map<int, int> m4{{2, 40}, {-4, 23}};
  m.swap(m3);
  auto i = m.begin();
  auto it = m3.begin();
  auto i2 = m.end();
  i2--;
  auto it2 = m3.end();
  it2--;
  m2.swap(m4);
  auto ite = m2.begin();
  auto iter = m4.begin();
  auto ite2 = m2.end();
  ite2--;
  auto iter2 = m4.end();
  iter2--;
  ASSERT_EQ((*i).first, ite->first);
  ASSERT_EQ((*it).first, iter->first);
  ASSERT_EQ((*i2).first, ite2->first);
  ASSERT_EQ((*it2).first, iter2->first);
}

TEST(TestMapSwap, SwapSecond) {
  containers::Map<int, int> m{{2, 40}, {-4, 23}};
  std::map<int, int> m2{{2, 40}, {-4, 23}};
  containers::Map<int, int> m3{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  std::map<int, int> m4{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  m.swap(m3);
  auto i = m.begin();
  auto it = m3.begin();
  auto i2 = m.end();
  i2--;
  auto it2 = m3.end();
  it2--;
  m2.swap(m4);
  auto ite = m2.begin();
  auto iter = m4.begin();
  auto ite2 = m2.end();
  ite2--;
  auto iter2 = m4.end();
  iter2--;
  ASSERT_EQ((*i).first, ite->first);
  ASSERT_EQ((*it).first, iter->first);
  ASSERT_EQ((*i2).first, ite2->first);
  ASSERT_EQ((*it2).first, iter2->first);
}

TEST(TestMapSwap, SwapThird) {
  containers::Map<int, int> m{{2, 40}, {-4, 23}, {6, 7}, {10, -6}};
  std::map<int, int> m2{{2, 40}, {-4, 23}, {6, 7}, {10, -6}};
  containers::Map<int, int> m3{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  std::map<int, int> m4{{1, 100}, {-3, 100}, {6, 100}, {4, 50}};
  m.swap(m3);
  auto i = m.begin();
  auto it = m3.begin();
  auto i2 = m.end();
  i2--;
  auto it2 = m3.end();
  it2--;
  m2.swap(m4);
  auto ite = m2.begin();
  auto iter = m4.begin();
  auto ite2 = m2.end();
  ite2--;
  auto iter2 = m4.end();
  iter2--;
  ASSERT_EQ((*i).first, ite->first);
  ASSERT_EQ((*it).first, iter->first);
  ASSERT_EQ((*i2).first, ite2->first);
  ASSERT_EQ((*it2).first, iter2->first);
}

TEST(TestMapInsert, InsertFirst) {
  containers::Map<int, int> m;
  std::pair<int, int> value = {1, 2};
  m.insert(value);
  value = {3, 4};
  m.insert(value);
  value = {5, 6};
  m.insert(value);
  value = {2, 3};
  m.insert(value);
  value = {-1, -9};
  m.insert(value);
  value = {-4, -9};
  m.insert(value);
  ASSERT_EQ(m[3], 4);
  ASSERT_EQ(m[5], 6);
  ASSERT_EQ(m[2], 3);
  ASSERT_EQ(m[-1], -9);
  ASSERT_EQ(m[-4], -9);
  ASSERT_EQ(m.size(), 6u);
}

TEST(TestMapInsert, InsertSecond) {
  containers::Map<int, int> m = {{-5, 100}};
  std::pair<int, int> value = {1, 2};
  m.insert(value);
  value = {3, 4};
  m.insert(value);
  value = {5, 6};
  m.insert(value);
  value = {2, 3};
  m.insert(value);
  value = {-1, -9};
  m.insert(value);
  value = {-4, -9};
  m.insert(value);
  ASSERT_EQ(m[-5], 100);
  ASSERT_EQ(m[1], 2);
  ASSERT_EQ(m[3], 4);
  ASSERT_EQ(m[5], 6);
  ASSERT_EQ(m[2], 3);
  ASSERT_EQ(m[-1], -9);
  ASSERT_EQ(m[-4], -9);
  ASSERT_EQ(m.size(), 7u);
}

TEST(TestMapInsert, InsertFifth) {
  containers::Map<int, int> m;
  std::pair<int, int> value = {1, 2};
  m.insert(value);
  value = {3, 4};
  m.insert(value);
  value = {5, 6};
  m.insert(value);
  value = {2, 3};
  m.insert(value);
  value = {-1, -9};
  m.insert(value);
  value = {-4, -9};
  m.insert(value);
  ASSERT_EQ(m[1], 2);
  ASSERT_EQ(m[3], 4);
  ASSERT_EQ(m[5], 6);
  ASSERT_EQ(m[2], 3);
  ASSERT_EQ(m[-1], -9);
  ASSERT_EQ(m[-4], -9);
  ASSERT_EQ(m.size(), 6u);
}

TEST(TestMapInsert, InsertThird) {
  containers::Map<int, int> m;
  std::pair<int, int> value = {1, 2};
  auto it = m.insert(value);
  std::map<int, int> m2;
  auto i = m2.insert(value);
  ASSERT_EQ(i.first->first, (*it.first).first);
  ASSERT_EQ(i.second, it.second);
}

TEST(TestMapInsert, InsertFourth) {
  containers::Map<int, int> m;
  m.insert(1, 2);
  m.insert(3, 4);
  m.insert(5, 6);
  m.insert(2, 3);
  m.insert(-1, -9);
  m.insert(-4, -9);
  ASSERT_EQ(m[3], 4);
  ASSERT_EQ(m[5], 6);
  ASSERT_EQ(m[2], 3);
  ASSERT_EQ(m[-1], -9);
  ASSERT_EQ(m[-4], -9);
  ASSERT_EQ(m.size(), 6u);
}

TEST(TestMapInsert, InsertSixth) {
  containers::Map<int, int> m;
  auto it = m.insert(1, 2);
  ASSERT_EQ(1, (*it.first).first);
  ASSERT_EQ(2, (*it.first).second);
  ASSERT_EQ(true, it.second);
}

TEST(TestMapInsert, InsertSeventh) {
  containers::Map<int, int> m;
  auto it = m.insert(20, 4);
  ASSERT_EQ(20, (*it.first).first);
  ASSERT_EQ(4, (*it.first).second);
  ASSERT_EQ(true, it.second);
  it = m.insert(10, 3);
  ASSERT_EQ(10, (*it.first).first);
  ASSERT_EQ(3, (*it.first).second);
  ASSERT_EQ(true, it.second);
  it = m.insert(4, 3);
  ASSERT_EQ(4, (*it.first).first);
  ASSERT_EQ(3, (*it.first).second);
  ASSERT_EQ(true, it.second);
  it = m.insert(2, 2);
  ASSERT_EQ(2, (*it.first).first);
  ASSERT_EQ(2, (*it.first).second);
  ASSERT_EQ(true, it.second);
  it = m.insert(5, 2);
  ASSERT_EQ(5, (*it.first).first);
  ASSERT_EQ(2, (*it.first).second);
  ASSERT_EQ(true, it.second);
  it = m.insert(16, 3);
  ASSERT_EQ(16, (*it.first).first);
  ASSERT_EQ(3, (*it.first).second);
  ASSERT_EQ(true, it.second);
  it = m.insert(3, 1);
  ASSERT_EQ(3, (*it.first).first);
  ASSERT_EQ(1, (*it.first).second);
  ASSERT_EQ(true, it.second);
  it = m.insert(14, 2);
  ASSERT_EQ(14, (*it.first).first);
  ASSERT_EQ(2, (*it.first).second);
  ASSERT_EQ(true, it.second);
  it = m.insert(17, 2);
  ASSERT_EQ(17, (*it.first).first);
  ASSERT_EQ(2, (*it.first).second);
  ASSERT_EQ(true, it.second);
  it = m.insert(12, 2);
  ASSERT_EQ(12, (*it.first).first);
  ASSERT_EQ(2, (*it.first).second);
  ASSERT_EQ(true, it.second);
  it = m.insert(15, 2);
  ASSERT_EQ(15, (*it.first).first);
  ASSERT_EQ(2, (*it.first).second);
  ASSERT_EQ(true, it.second);
  it = m.insert(11, 1);
  ASSERT_EQ(11, (*it.first).first);
  ASSERT_EQ(1, (*it.first).second);
  ASSERT_EQ(true, it.second);
  it = m.insert(std::make_pair(19, 1));
  ASSERT_EQ(19, (*it.first).first);
  ASSERT_EQ(1, (*it.first).second);
  ASSERT_EQ(true, it.second);
  it = m.insert(std::make_pair(25, 3));
  ASSERT_EQ(25, (*it.first).first);
  ASSERT_EQ(3, (*it.first).second);
  ASSERT_EQ(true, it.second);
  it = m.insert(std::make_pair(23, 2));
  ASSERT_EQ(23, (*it.first).first);
  ASSERT_EQ(2, (*it.first).second);
  ASSERT_EQ(true, it.second);
  it = m.insert(std::make_pair(30, 2));
  ASSERT_EQ(30, (*it.first).first);
  ASSERT_EQ(2, (*it.first).second);
  ASSERT_EQ(true, it.second);
  it = m.insert(std::make_pair(1, 4));
  ASSERT_EQ(1, (*it.first).first);
  ASSERT_EQ(4, (*it.first).second);
  ASSERT_EQ(true, it.second);
}

TEST(TestMapInsert, InsertEighth) {
  containers::Map<std::string, char> m{
      {"sentence", 'b'}, {"not", 'd'}, {"word", 'e'}};
  m.insert("this", 'a');
  m.insert({"is", 'c'});
  m.insert({"a", 'f'});
  ASSERT_EQ(m["this"], 'a');
  ASSERT_EQ(m["is"], 'c');
  ASSERT_EQ(m["a"], 'f');
  ASSERT_EQ(m["sentence"], 'b');
  ASSERT_EQ(m["not"], 'd');
  ASSERT_EQ(m["word"], 'e');
  ASSERT_EQ(m.size(), 6u);
}

TEST(TestMapInsertOrAssign, InsertOrAssignFirst) {
  containers::Map<int, int> m;
  m.insert_or_assign(1, 2);
  m.insert_or_assign(3, 4);
  m.insert_or_assign(5, 6);
  m.insert_or_assign(2, 3);
  m.insert_or_assign(-1, -9);
  m.insert_or_assign(-4, -9);
  ASSERT_EQ(m[1], 2);
  ASSERT_EQ(m[3], 4);
  ASSERT_EQ(m[5], 6);
  ASSERT_EQ(m[2], 3);
  ASSERT_EQ(m[-1], -9);
  ASSERT_EQ(m[-4], -9);
  ASSERT_EQ(m.size(), 6u);
}

TEST(TestMapInsertOrAssign, InsertOrAssignSecond) {
  containers::Map<int, int> m = {{-5, 100}};
  m.insert_or_assign(1, 2);
  m.insert_or_assign(3, 4);
  m.insert_or_assign(5, 6);
  m.insert_or_assign(2, 3);
  m.insert_or_assign(-1, -9);
  m.insert_or_assign(-4, -9);
  ASSERT_EQ(m[-5], 100);
  ASSERT_EQ(m[1], 2);
  ASSERT_EQ(m[3], 4);
  ASSERT_EQ(m[5], 6);
  ASSERT_EQ(m[2], 3);
  ASSERT_EQ(m[-1], -9);
  ASSERT_EQ(m[-4], -9);
  ASSERT_EQ(m.size(), 7u);
}

TEST(TestMapInsertOrAssign, InsertOrAssignThird) {
  containers::Map<int, int> m = {{-5, 100}};
  auto iter = m.insert_or_assign(-5, 100);
  std::map<int, int> m2 = {{-5, 100}};
  auto it = m2.insert_or_assign(-5, 100);
  ASSERT_EQ(iter.second, it.second);
  ASSERT_EQ(it.first->first, (*iter.first).first);
  ASSERT_EQ(m.size(), 1u);
}

TEST(TestMapInsertOrAssign, InsertOrAssignFourth) {
  containers::Map<int, int> m = {{20, 4}, {10, 3}, {2, 2},  {5, 2},  {16, 3},
                                 {14, 2}, {17, 2}, {12, 2}, {15, 2}, {11, 1},
                                 {19, 1}, {25, 3}, {23, 2}, {30, 2}};
  m.insert_or_assign(1, 2);
  m.insert_or_assign(3, 4);
  m.insert_or_assign(-1, -9);
  m.insert_or_assign(-4, -9);
  ASSERT_EQ(m.size(), 18u);
  ASSERT_EQ(m[20], 4);
  ASSERT_EQ(m[10], 3);
  ASSERT_EQ(m[2], 2);
  ASSERT_EQ(m[5], 2);
  ASSERT_EQ(m[16], 3);
  ASSERT_EQ(m[14], 2);
  ASSERT_EQ(m[17], 2);
  ASSERT_EQ(m[12], 2);
  ASSERT_EQ(m[15], 2);
  ASSERT_EQ(m[11], 1);
  ASSERT_EQ(m[19], 1);
  ASSERT_EQ(m[25], 3);
  ASSERT_EQ(m[23], 2);
  ASSERT_EQ(m[30], 2);
  ASSERT_EQ(m[1], 2);
  ASSERT_EQ(m[3], 4);
  ASSERT_EQ(m[-1], -9);
  ASSERT_EQ(m[-4], -9);
}

TEST(TestMapInsertOrAssign, InsertOrAssignFifth) {
  containers::Map<int, int> m = {{20, 4}, {10, 3}, {2, 2},  {5, 2},  {16, 3},
                                 {14, 2}, {17, 2}, {12, 2}, {15, 2}, {11, 1},
                                 {19, 1}, {25, 3}, {23, 2}, {30, 2}};
  auto iter = m.insert_or_assign(20, 4);
  std::map<int, int> m2 = {{20, 4}, {10, 3}, {2, 2},  {5, 2},  {16, 3},
                           {14, 2}, {17, 2}, {12, 2}, {15, 2}, {11, 1},
                           {19, 1}, {25, 3}, {23, 2}, {30, 2}};
  auto it = m2.insert_or_assign(20, 4);
  ASSERT_EQ(m.size(), 14u);
  ASSERT_EQ(m[20], 4);
  ASSERT_EQ(m[10], 3);
  ASSERT_EQ(m[2], 2);
  ASSERT_EQ(m[5], 2);
  ASSERT_EQ(m[16], 3);
  ASSERT_EQ(m[14], 2);
  ASSERT_EQ(m[17], 2);
  ASSERT_EQ(m[12], 2);
  ASSERT_EQ(m[15], 2);
  ASSERT_EQ(m[11], 1);
  ASSERT_EQ(m[19], 1);
  ASSERT_EQ(m[25], 3);
  ASSERT_EQ(m[23], 2);
  ASSERT_EQ(m[30], 2);
  ASSERT_EQ(iter.second, it.second);
  ASSERT_EQ(it.first->first, (*iter.first).first);
}

TEST(TestMapOperatorBracket, OperatorBracketFirst) {
  containers::Map<int, int> m = {{-5, 100}};
  ASSERT_EQ(m[-5], 100);
  ASSERT_EQ(m[1], 0);
}

TEST(TestMapOperatorBracket, OperatorBracketSecond) {
  containers::Map<int, char> m = {{-5, 'a'}};
  ASSERT_EQ(m[-5], 'a');
  ASSERT_EQ(m[1], '\0');
}

TEST(TestMapOperatorAt, OperatorAt) {
  containers::Map<int, int> m = {{-5, 100}};
  EXPECT_ANY_THROW(m.at(1));
}

TEST(TestMapOperatorAt, OperatorAtSecond) {
  containers::Map<int, int> m = {{-5, 100}};
  ASSERT_EQ(m.at(-5), 100);
}

TEST(TestMapMerge, MergeFirst) {
  containers::Map<int, int> m = {{-5, 100}};
  containers::Map<int, int> m2 = {{1, 10}, {-3, 20}, {6, 30},  {4, 40},
                                  {3, 50}, {-1, 60}, {-10, 70}};
  m.merge(m2);
  ASSERT_EQ(m.size(), 8u);
  ASSERT_EQ(m[-5], 100);
  ASSERT_EQ(m[1], 10);
  ASSERT_EQ(m[-3], 20);
  ASSERT_EQ(m[6], 30);
  ASSERT_EQ(m[4], 40);
  ASSERT_EQ(m[3], 50);
  ASSERT_EQ(m[-1], 60);
  ASSERT_EQ(m[-10], 70);
}

TEST(TestMapMerge, MergeSecond) {
  containers::Map<int, int> m = {{1, 10}, {-3, 20}, {6, 30},  {4, 40},
                                 {3, 50}, {-1, 60}, {-10, 70}};
  containers::Map<int, int> m2 = {{-5, 100}};
  m.merge(m2);
  ASSERT_EQ(m.size(), 8u);
  ASSERT_EQ(m[-5], 100);
  ASSERT_EQ(m[1], 10);
  ASSERT_EQ(m[-3], 20);
  ASSERT_EQ(m[6], 30);
  ASSERT_EQ(m[4], 40);
  ASSERT_EQ(m[3], 50);
  ASSERT_EQ(m[-1], 60);
  ASSERT_EQ(m[-10], 70);
}

TEST(TestMapMerge, MergeThird) {
  containers::Map<int, int> m = {{1, 10}, {-3, 20}, {6, 30},  {4, 40},
                                 {3, 50}, {-1, 60}, {-10, 70}};
  containers::Map<int, int> m2 = {{20, 4}, {10, 3}, {2, 2},  {5, 2},  {16, 3},
                                  {14, 2}, {17, 2}, {12, 2}, {15, 2}, {11, 1},
                                  {19, 1}, {25, 3}, {23, 2}, {30, 2}};
  m.merge(m2);
  ASSERT_EQ(m.size(), 21u);
  ASSERT_EQ(m[1], 10);
  ASSERT_EQ(m[-3], 20);
  ASSERT_EQ(m[6], 30);
  ASSERT_EQ(m[4], 40);
  ASSERT_EQ(m[3], 50);
  ASSERT_EQ(m[-1], 60);
  ASSERT_EQ(m[-10], 70);
  ASSERT_EQ(m[20], 4);
  ASSERT_EQ(m[10], 3);
  ASSERT_EQ(m[2], 2);
  ASSERT_EQ(m[5], 2);
  ASSERT_EQ(m[16], 3);
  ASSERT_EQ(m[14], 2);
  ASSERT_EQ(m[17], 2);
  ASSERT_EQ(m[12], 2);
  ASSERT_EQ(m[15], 2);
  ASSERT_EQ(m[11], 1);
  ASSERT_EQ(m[19], 1);
  ASSERT_EQ(m[25], 3);
  ASSERT_EQ(m[23], 2);
  ASSERT_EQ(m[30], 2);
}

TEST(TestMapErase, EraseFirst) {
  containers::Map<int, int> m = {{1, 10}, {-3, 20}, {6, 30},  {4, 40},
                                 {3, 50}, {-1, 60}, {-10, 70}};
  auto it = m.begin();
  m.erase(it);
  ASSERT_EQ(m.size(), 6u);
  ASSERT_EQ(m[1], 10);
  ASSERT_EQ(m[-1], 60);
  ASSERT_EQ(m[6], 30);
  ASSERT_EQ(m[4], 40);
  ASSERT_EQ(m[3], 50);
}

TEST(TestMapErase, EraseSecond) {
  containers::Map<int, int> m = {{1, 10}};
  auto it = m.begin();
  m.erase(it);
  ASSERT_EQ(m.size(), 0u);
}

TEST(TestMapErase, EraseThird) {
  containers::Map<int, int> m = {
      {100, 10}, {90, 20}, {10, 30}, {150, 40}, {50, 50}};
  auto it = m.begin();
  m.erase(it);
  ASSERT_EQ(m.size(), 4u);
  ASSERT_EQ(m[100], 10);
  ASSERT_EQ(m[90], 20);
  ASSERT_EQ(m[150], 40);
  ASSERT_EQ(m[50], 50);
}

TEST(TestMapErase, EraseFourth) {
  containers::Map<int, int> m = {{1, 10}, {-3, 20}, {6, 30},   {4, 40},
                                 {3, 50}, {-1, 60}, {-10, 70}, {-11, 110}};
  auto it = m.begin();
  it++;
  m.erase(it);
  ASSERT_EQ(m.size(), 7u);
  ASSERT_EQ(m[1], 10);
  ASSERT_EQ(m[-1], 60);
  ASSERT_EQ(m[6], 30);
  ASSERT_EQ(m[4], 40);
  ASSERT_EQ(m[3], 50);
  ASSERT_EQ(m[-11], 110);
}

TEST(TestMapErase, EraseFifth) {
  containers::Map<int, int> m = {{1, 10}, {-3, 20}, {6, 30},  {4, 40},
                                 {3, 50}, {-1, 60}, {-10, 70}};
  auto it = m.begin();
  it++;
  m.erase(it);
  ASSERT_EQ(m.size(), 6u);
  ASSERT_EQ(m[1], 10);
  ASSERT_EQ(m[-1], 60);
  ASSERT_EQ(m[6], 30);
  ASSERT_EQ(m[4], 40);
  ASSERT_EQ(m[3], 50);
  ASSERT_EQ(m[-10], 70);
}

TEST(TestMapErase, EraseSixth) {
  containers::Map<int, int> m = {
      {20, 4}, {10, 3}, {4, 3},  {2, 2},  {5, 2},  {16, 3}, {3, 1},  {14, 2},
      {17, 2}, {12, 2}, {15, 2}, {11, 1}, {19, 1}, {25, 3}, {23, 2}, {30, 2}};
  auto it = m.begin();
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  m.erase(it);
  ASSERT_EQ(m.size(), 15u);
  ASSERT_EQ(m[20], 4);
  ASSERT_EQ(m[10], 3);
  ASSERT_EQ(m[4], 3);
  ASSERT_EQ(m[2], 2);
  ASSERT_EQ(m[5], 2);
  ASSERT_EQ(m[16], 3);
  ASSERT_EQ(m[3], 1);
  ASSERT_EQ(m[14], 2);
  ASSERT_EQ(m[17], 2);
  ASSERT_EQ(m[12], 2);
  ASSERT_EQ(m[11], 1);
  ASSERT_EQ(m[19], 1);
  ASSERT_EQ(m[25], 3);
  ASSERT_EQ(m[23], 2);
  ASSERT_EQ(m[30], 2);
}

TEST(TestMapErase, EraseSeventh) {
  containers::Map<int, int> m = {
      {20, 4}, {10, 3}, {4, 3},  {2, 2},  {5, 2},  {16, 3}, {3, 1},  {14, 2},
      {17, 2}, {12, 2}, {15, 2}, {11, 1}, {19, 1}, {25, 3}, {23, 2}, {30, 2}};
  auto it = m.begin();
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  m.erase(it);
  ASSERT_EQ(m.size(), 15u);
  ASSERT_EQ(m[20], 4);
  ASSERT_EQ(m[10], 3);
  ASSERT_EQ(m[4], 3);
  ASSERT_EQ(m[2], 2);
  ASSERT_EQ(m[5], 2);
  ASSERT_EQ(m[16], 3);
  ASSERT_EQ(m[3], 1);
  ASSERT_EQ(m[17], 2);
  ASSERT_EQ(m[12], 2);
  ASSERT_EQ(m[15], 2);
  ASSERT_EQ(m[11], 1);
  ASSERT_EQ(m[19], 1);
  ASSERT_EQ(m[25], 3);
  ASSERT_EQ(m[23], 2);
  ASSERT_EQ(m[30], 2);
}

TEST(TestMapErase, EraseEighth) {
  containers::Map<int, int> m = {
      {20, 4}, {10, 3}, {4, 3},  {2, 2},  {5, 2},  {16, 3}, {3, 1},  {14, 2},
      {17, 2}, {12, 2}, {15, 2}, {11, 1}, {19, 1}, {25, 3}, {23, 2}, {30, 2}};
  auto it = m.begin();
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  m.erase(it);
  ASSERT_EQ(m.size(), 15u);
  ASSERT_EQ(m[20], 4);
  ASSERT_EQ(m[10], 3);
  ASSERT_EQ(m[4], 3);
  ASSERT_EQ(m[2], 2);
  ASSERT_EQ(m[5], 2);
  ASSERT_EQ(m[16], 3);
  ASSERT_EQ(m[3], 1);
  ASSERT_EQ(m[15], 2);
  ASSERT_EQ(m[17], 2);
  ASSERT_EQ(m[14], 2);
  ASSERT_EQ(m[11], 1);
  ASSERT_EQ(m[19], 1);
  ASSERT_EQ(m[25], 3);
  ASSERT_EQ(m[23], 2);
  ASSERT_EQ(m[30], 2);
}

TEST(TestMapErase, EraseNinth) {
  containers::Map<int, int> m = {
      {20, 4}, {10, 3}, {4, 3},  {2, 2},  {5, 2},  {16, 3}, {3, 1},  {14, 2},
      {17, 2}, {12, 2}, {15, 2}, {11, 1}, {19, 1}, {25, 3}, {23, 2}, {30, 2}};
  auto it = m.begin();
  it++;
  it++;
  it++;
  it++;
  it++;
  m.erase(it);
  ASSERT_EQ(m.size(), 15u);
  ASSERT_EQ(m[20], 4);
  ASSERT_EQ(m[10], 3);
  ASSERT_EQ(m[4], 3);
  ASSERT_EQ(m[2], 2);
  ASSERT_EQ(m[5], 2);
  ASSERT_EQ(m[16], 3);
  ASSERT_EQ(m[3], 1);
  ASSERT_EQ(m[15], 2);
  ASSERT_EQ(m[17], 2);
  ASSERT_EQ(m[14], 2);
  ASSERT_EQ(m[12], 2);
  ASSERT_EQ(m[19], 1);
  ASSERT_EQ(m[25], 3);
  ASSERT_EQ(m[23], 2);
  ASSERT_EQ(m[30], 2);
}

TEST(TestMapErase, EraseTenth) {
  containers::Map<int, int> m = {
      {20, 4}, {10, 3}, {4, 3},  {2, 2},  {5, 2},  {16, 3}, {3, 1},  {14, 2},
      {17, 2}, {12, 2}, {15, 2}, {11, 1}, {19, 1}, {25, 3}, {23, 2}, {30, 2}};
  auto it = m.begin();
  it++;
  it++;
  it++;
  it++;
  m.erase(it);
  ASSERT_EQ(m.size(), 15u);
  ASSERT_EQ(m[20], 4);
  ASSERT_EQ(m[11], 1);
  ASSERT_EQ(m[4], 3);
  ASSERT_EQ(m[2], 2);
  ASSERT_EQ(m[5], 2);
  ASSERT_EQ(m[16], 3);
  ASSERT_EQ(m[3], 1);
  ASSERT_EQ(m[15], 2);
  ASSERT_EQ(m[17], 2);
  ASSERT_EQ(m[14], 2);
  ASSERT_EQ(m[12], 2);
  ASSERT_EQ(m[19], 1);
  ASSERT_EQ(m[25], 3);
  ASSERT_EQ(m[23], 2);
  ASSERT_EQ(m[30], 2);
}

TEST(TestMapErase, EraseEleventh) {
  containers::Map<int, int> m = {
      {20, 4}, {10, 3}, {4, 3},  {2, 2},  {5, 2},  {16, 3}, {3, 1},  {14, 2},
      {17, 2}, {12, 2}, {15, 2}, {11, 1}, {19, 1}, {25, 3}, {23, 2}, {30, 2}};
  auto it = m.begin();
  it++;
  it++;
  it++;
  m.erase(it);
  ASSERT_EQ(m.size(), 15u);
  ASSERT_EQ(m[20], 4);
  ASSERT_EQ(m[11], 1);
  ASSERT_EQ(m[4], 3);
  ASSERT_EQ(m[2], 2);
  ASSERT_EQ(m[10], 3);
  ASSERT_EQ(m[16], 3);
  ASSERT_EQ(m[3], 1);
  ASSERT_EQ(m[15], 2);
  ASSERT_EQ(m[17], 2);
  ASSERT_EQ(m[14], 2);
  ASSERT_EQ(m[12], 2);
  ASSERT_EQ(m[19], 1);
  ASSERT_EQ(m[25], 3);
  ASSERT_EQ(m[23], 2);
  ASSERT_EQ(m[30], 2);
}

TEST(TestMapErase, EraseTwelfth) {
  containers::Map<int, int> m = {
      {20, 4}, {10, 3}, {4, 3},  {2, 2},  {5, 2},  {16, 3}, {3, 1},  {14, 2},
      {17, 2}, {12, 2}, {15, 2}, {11, 1}, {19, 1}, {25, 3}, {23, 2}, {30, 2}};
  auto it = m.begin();
  it++;
  it++;
  m.erase(it);
  ASSERT_EQ(m.size(), 15u);
  ASSERT_EQ(m[20], 4);
  ASSERT_EQ(m[10], 3);
  ASSERT_EQ(m[2], 2);
  ASSERT_EQ(m[5], 2);
  ASSERT_EQ(m[11], 1);
  ASSERT_EQ(m[16], 3);
  ASSERT_EQ(m[3], 1);
  ASSERT_EQ(m[15], 2);
  ASSERT_EQ(m[17], 2);
  ASSERT_EQ(m[14], 2);
  ASSERT_EQ(m[12], 2);
  ASSERT_EQ(m[19], 1);
  ASSERT_EQ(m[25], 3);
  ASSERT_EQ(m[23], 2);
  ASSERT_EQ(m[30], 2);
}

TEST(TestMapErase, EraseThirteenth) {
  containers::Map<int, int> m = {
      {20, 4}, {10, 3}, {4, 3},  {2, 2},  {5, 2},  {16, 3}, {3, 1},  {14, 2},
      {17, 2}, {12, 2}, {15, 2}, {11, 1}, {19, 1}, {25, 3}, {23, 2}, {30, 2}};
  auto it = m.begin();
  it++;
  m.erase(it);
  ASSERT_EQ(m.size(), 15u);
  ASSERT_EQ(m[20], 4);
  ASSERT_EQ(m[11], 1);
  ASSERT_EQ(m[4], 3);
  ASSERT_EQ(m[2], 2);
  ASSERT_EQ(m[5], 2);
  ASSERT_EQ(m[16], 3);
  ASSERT_EQ(m[10], 3);
  ASSERT_EQ(m[15], 2);
  ASSERT_EQ(m[17], 2);
  ASSERT_EQ(m[14], 2);
  ASSERT_EQ(m[12], 2);
  ASSERT_EQ(m[19], 1);
  ASSERT_EQ(m[25], 3);
  ASSERT_EQ(m[23], 2);
  ASSERT_EQ(m[30], 2);
}

TEST(TestMapErase, EraseFourteenth) {
  containers::Map<int, int> m = {
      {20, 4}, {10, 3}, {4, 3},  {2, 2},  {5, 2},  {16, 3}, {3, 1},  {14, 2},
      {17, 2}, {12, 2}, {15, 2}, {11, 1}, {19, 1}, {25, 3}, {23, 2}, {30, 2}};
  auto it = m.begin();
  m.erase(it);
  ASSERT_EQ(m.size(), 15u);
  ASSERT_EQ(m[20], 4);
  ASSERT_EQ(m[11], 1);
  ASSERT_EQ(m[4], 3);
  ASSERT_EQ(m[10], 3);
  ASSERT_EQ(m[5], 2);
  ASSERT_EQ(m[16], 3);
  ASSERT_EQ(m[3], 1);
  ASSERT_EQ(m[15], 2);
  ASSERT_EQ(m[17], 2);
  ASSERT_EQ(m[14], 2);
  ASSERT_EQ(m[12], 2);
  ASSERT_EQ(m[19], 1);
  ASSERT_EQ(m[25], 3);
  ASSERT_EQ(m[23], 2);
  ASSERT_EQ(m[30], 2);
}

TEST(TestMapErase, EraseFifteenth) {
  containers::Map<int, int> m = {
      {20, 4}, {10, 3}, {4, 3},  {2, 2},  {5, 2},  {16, 3}, {3, 1},  {14, 2},
      {17, 2}, {12, 2}, {15, 2}, {11, 1}, {19, 1}, {25, 3}, {23, 2}, {30, 2}};
  auto it = m.begin();
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  m.erase(it);
  ASSERT_EQ(m.size(), 15u);
  ASSERT_EQ(m[20], 4);
  ASSERT_EQ(m[10], 3);
  ASSERT_EQ(m[4], 3);
  ASSERT_EQ(m[2], 2);
  ASSERT_EQ(m[5], 2);
  ASSERT_EQ(m[15], 2);
  ASSERT_EQ(m[3], 1);
  ASSERT_EQ(m[14], 2);
  ASSERT_EQ(m[17], 2);
  ASSERT_EQ(m[12], 2);
  ASSERT_EQ(m[11], 1);
  ASSERT_EQ(m[19], 1);
  ASSERT_EQ(m[25], 3);
  ASSERT_EQ(m[23], 2);
  ASSERT_EQ(m[30], 2);
}

TEST(TestMapErase, EraseNineteenth) {
  containers::Map<int, int> m = {
      {20, 4}, {10, 3}, {4, 3},  {2, 2},  {5, 2},  {16, 3}, {3, 1},  {14, 2},
      {17, 2}, {12, 2}, {15, 2}, {11, 1}, {19, 1}, {25, 3}, {23, 2}, {30, 2}};
  auto it = m.begin();
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  m.erase(it);
  ASSERT_EQ(m.size(), 15u);
  ASSERT_EQ(m[20], 4);
  ASSERT_EQ(m[10], 3);
  ASSERT_EQ(m[4], 3);
  ASSERT_EQ(m[2], 2);
  ASSERT_EQ(m[5], 2);
  ASSERT_EQ(m[16], 3);
  ASSERT_EQ(m[3], 1);
  ASSERT_EQ(m[14], 2);
  ASSERT_EQ(m[15], 2);
  ASSERT_EQ(m[12], 2);
  ASSERT_EQ(m[11], 1);
  ASSERT_EQ(m[19], 1);
  ASSERT_EQ(m[25], 3);
  ASSERT_EQ(m[23], 2);
  ASSERT_EQ(m[30], 2);
}

TEST(TestMapErase, EraseSixteenth) {
  containers::Map<int, int> m = {
      {20, 4}, {10, 3}, {4, 3},  {2, 2},  {5, 2},  {16, 3}, {3, 1},  {14, 2},
      {17, 2}, {12, 2}, {15, 2}, {11, 1}, {19, 1}, {25, 3}, {23, 2}, {30, 2}};
  auto it = m.begin();
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  m.erase(it);
  ASSERT_EQ(m.size(), 15u);
  ASSERT_EQ(m[20], 4);
  ASSERT_EQ(m[10], 3);
  ASSERT_EQ(m[4], 3);
  ASSERT_EQ(m[2], 2);
  ASSERT_EQ(m[5], 2);
  ASSERT_EQ(m[16], 3);
  ASSERT_EQ(m[3], 1);
  ASSERT_EQ(m[14], 2);
  ASSERT_EQ(m[17], 2);
  ASSERT_EQ(m[12], 2);
  ASSERT_EQ(m[11], 1);
  ASSERT_EQ(m[15], 2);
  ASSERT_EQ(m[25], 3);
  ASSERT_EQ(m[23], 2);
  ASSERT_EQ(m[30], 2);
}

TEST(TestMapErase, EraseSeventeenth) {
  containers::Map<int, int> m = {
      {20, 4}, {10, 3}, {4, 3},  {2, 2},  {5, 2},  {16, 3}, {3, 1},  {14, 2},
      {17, 2}, {12, 2}, {15, 2}, {11, 1}, {19, 1}, {25, 3}, {23, 2}, {30, 2}};
  auto it = m.begin();
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  m.erase(it);
  ASSERT_EQ(m.size(), 15u);
  ASSERT_EQ(m[15], 2);
  ASSERT_EQ(m[10], 3);
  ASSERT_EQ(m[4], 3);
  ASSERT_EQ(m[2], 2);
  ASSERT_EQ(m[5], 2);
  ASSERT_EQ(m[16], 3);
  ASSERT_EQ(m[3], 1);
  ASSERT_EQ(m[14], 2);
  ASSERT_EQ(m[17], 2);
  ASSERT_EQ(m[12], 2);
  ASSERT_EQ(m[11], 1);
  ASSERT_EQ(m[19], 1);
  ASSERT_EQ(m[25], 3);
  ASSERT_EQ(m[23], 2);
  ASSERT_EQ(m[30], 2);
}

TEST(TestMapErase, EraseEighteenth) {
  containers::Map<int, int> m = {
      {20, 4}, {10, 3}, {4, 3},  {2, 2},  {5, 2},  {16, 3}, {3, 1},  {14, 2},
      {17, 2}, {12, 2}, {15, 2}, {11, 1}, {19, 1}, {25, 3}, {23, 2}, {30, 2}};
  auto it = m.begin();
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  m.erase(it);
  ASSERT_EQ(m.size(), 15u);
  ASSERT_EQ(m[20], 4);
  ASSERT_EQ(m[10], 3);
  ASSERT_EQ(m[4], 3);
  ASSERT_EQ(m[2], 2);
  ASSERT_EQ(m[5], 2);
  ASSERT_EQ(m[16], 3);
  ASSERT_EQ(m[3], 1);
  ASSERT_EQ(m[14], 2);
  ASSERT_EQ(m[17], 2);
  ASSERT_EQ(m[12], 2);
  ASSERT_EQ(m[11], 1);
  ASSERT_EQ(m[19], 1);
  ASSERT_EQ(m[15], 2);
  ASSERT_EQ(m[23], 2);
  ASSERT_EQ(m[30], 2);
}

TEST(TestMapErase, EraseTwentieth) {
  containers::Map<int, int> m = {
      {20, 4}, {10, 3}, {4, 3},  {2, 2},  {5, 2},  {16, 3}, {3, 1},  {14, 2},
      {17, 2}, {12, 2}, {15, 2}, {11, 1}, {19, 1}, {25, 3}, {23, 2}, {30, 2}};
  auto it = m.begin();
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  m.erase(it);
  ASSERT_EQ(m.size(), 15u);
  ASSERT_EQ(m[20], 4);
  ASSERT_EQ(m[10], 3);
  ASSERT_EQ(m[4], 3);
  ASSERT_EQ(m[2], 2);
  ASSERT_EQ(m[5], 2);
  ASSERT_EQ(m[16], 3);
  ASSERT_EQ(m[3], 1);
  ASSERT_EQ(m[14], 2);
  ASSERT_EQ(m[17], 2);
  ASSERT_EQ(m[12], 2);
  ASSERT_EQ(m[11], 1);
  ASSERT_EQ(m[19], 1);
  ASSERT_EQ(m[15], 2);
  ASSERT_EQ(m[25], 3);
  ASSERT_EQ(m[30], 2);
}

TEST(TestMapErase, EraseTwentyFirst) {
  containers::Map<int, int> m = {
      {20, 4}, {10, 3}, {4, 3},  {2, 2},  {5, 2},  {16, 3}, {3, 1},  {14, 2},
      {17, 2}, {12, 2}, {15, 2}, {11, 1}, {19, 1}, {25, 3}, {23, 2}, {30, 2}};
  auto it = m.begin();
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  m.erase(it);
  ASSERT_EQ(m.size(), 15u);
  ASSERT_EQ(m[20], 4);
  ASSERT_EQ(m[10], 3);
  ASSERT_EQ(m[4], 3);
  ASSERT_EQ(m[2], 2);
  ASSERT_EQ(m[5], 2);
  ASSERT_EQ(m[16], 3);
  ASSERT_EQ(m[3], 1);
  ASSERT_EQ(m[14], 2);
  ASSERT_EQ(m[17], 2);
  ASSERT_EQ(m[12], 2);
  ASSERT_EQ(m[11], 1);
  ASSERT_EQ(m[19], 1);
  ASSERT_EQ(m[15], 2);
  ASSERT_EQ(m[23], 2);
  ASSERT_EQ(m[25], 3);
}

TEST(TestMapErase, EraseTwentySecond) {
  containers::Map<int, int> m = {{20, 4}, {10, 3}, {4, 3},  {2, 2},  {5, 2},
                                 {16, 3}, {3, 1},  {14, 2}, {17, 2}, {12, 2},
                                 {15, 2}, {11, 1}, {19, 1}, {25, 3}, {23, 2},
                                 {30, 2}, {1, 4}};
  auto it = m.begin();
  it++;
  m.erase(it);
  ASSERT_EQ(m.size(), 16u);
  ASSERT_EQ(m[20], 4);
  ASSERT_EQ(m[10], 3);
  ASSERT_EQ(m[4], 3);
  ASSERT_EQ(m[3], 1);
  ASSERT_EQ(m[5], 2);
  ASSERT_EQ(m[16], 3);
  ASSERT_EQ(m[1], 4);
  ASSERT_EQ(m[14], 2);
  ASSERT_EQ(m[17], 2);
  ASSERT_EQ(m[12], 2);
  ASSERT_EQ(m[11], 1);
  ASSERT_EQ(m[19], 1);
  ASSERT_EQ(m[15], 2);
  ASSERT_EQ(m[23], 2);
  ASSERT_EQ(m[25], 3);
  ASSERT_EQ(m[30], 2);
}

TEST(TestMapErase, EraseTwentyThird) {
  containers::Map<int, int> m = {{20, 4}, {10, 3}, {4, 3},  {2, 2},  {5, 2},
                                 {16, 3}, {3, 1},  {14, 2}, {17, 2}, {12, 2},
                                 {15, 2}, {11, 1}, {19, 1}, {25, 3}, {23, 2},
                                 {30, 2}, {1, 4}};
  auto it = m.begin();
  it++;
  it++;
  m.erase(it);
  ASSERT_EQ(m.size(), 16u);
  ASSERT_EQ(m[20], 4);
  ASSERT_EQ(m[10], 3);
  ASSERT_EQ(m[4], 3);
  ASSERT_EQ(m[2], 2);
  ASSERT_EQ(m[5], 2);
  ASSERT_EQ(m[16], 3);
  ASSERT_EQ(m[1], 4);
  ASSERT_EQ(m[14], 2);
  ASSERT_EQ(m[17], 2);
  ASSERT_EQ(m[12], 2);
  ASSERT_EQ(m[11], 1);
  ASSERT_EQ(m[19], 1);
  ASSERT_EQ(m[15], 2);
  ASSERT_EQ(m[23], 2);
  ASSERT_EQ(m[25], 3);
  ASSERT_EQ(m[30], 2);
}

TEST(TestMapErase, EraseTwentyFourth) {
  containers::Map<int, int> m = {{20, 4}, {10, 3}, {4, 3},  {2, 2},  {5, 2},
                                 {16, 3}, {3, 1},  {14, 2}, {17, 2}, {12, 2},
                                 {15, 2}, {11, 1}, {19, 1}, {25, 3}, {23, 2},
                                 {30, 2}, {1, 4}};
  auto it = m.begin();
  it++;
  it++;
  it++;
  m.erase(it);
  ASSERT_EQ(m.size(), 16u);
  ASSERT_EQ(m[20], 4);
  ASSERT_EQ(m[10], 3);
  ASSERT_EQ(m[2], 2);
  ASSERT_EQ(m[2], 2);
  ASSERT_EQ(m[5], 2);
  ASSERT_EQ(m[16], 3);
  ASSERT_EQ(m[1], 4);
  ASSERT_EQ(m[14], 2);
  ASSERT_EQ(m[17], 2);
  ASSERT_EQ(m[12], 2);
  ASSERT_EQ(m[11], 1);
  ASSERT_EQ(m[19], 1);
  ASSERT_EQ(m[15], 2);
  ASSERT_EQ(m[23], 2);
  ASSERT_EQ(m[25], 3);
  ASSERT_EQ(m[30], 2);
}

TEST(TestMapErase, EraseTwentyFifth) {
  containers::Map<int, int> m = {{20, 4}, {10, 3}, {4, 3},  {2, 2},  {5, 2},
                                 {3, 1},  {14, 2}, {17, 2}, {12, 2}, {15, 2},
                                 {11, 1}, {19, 1}, {25, 3}, {18, 1}};
  auto it = m.begin();
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  m.erase(it);
  ASSERT_EQ(m.size(), 13u);
  ASSERT_EQ(m[20], 4);
  ASSERT_EQ(m[10], 3);
  ASSERT_EQ(m[4], 3);
  ASSERT_EQ(m[2], 2);
  ASSERT_EQ(m[5], 2);
  ASSERT_EQ(m[3], 1);
  ASSERT_EQ(m[14], 2);
  ASSERT_EQ(m[12], 2);
  ASSERT_EQ(m[15], 2);
  ASSERT_EQ(m[11], 1);
  ASSERT_EQ(m[19], 1);
  ASSERT_EQ(m[25], 3);
  ASSERT_EQ(m[18], 1);
}

TEST(TestMapErase, EraseTwentySixth) {
  containers::Map<int, int> m = {{20, 4}, {10, 3}, {4, 3},  {2, 2},
                                 {5, 2},  {3, 1},  {14, 2}, {17, 2},
                                 {12, 2}, {15, 2}, {11, 1}, {19, 1}};
  auto it = m.begin();
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  m.erase(it);
  it = m.begin();
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  it++;
  m.erase(it);
  ASSERT_EQ(m.size(), 10u);
  ASSERT_EQ(m[20], 4);
  ASSERT_EQ(m[10], 3);
  ASSERT_EQ(m[4], 3);
  ASSERT_EQ(m[2], 2);
  ASSERT_EQ(m[5], 2);
  ASSERT_EQ(m[3], 1);
  ASSERT_EQ(m[12], 2);
  ASSERT_EQ(m[15], 2);
  ASSERT_EQ(m[11], 1);
  ASSERT_EQ(m[19], 1);
}

TEST(TestMapErase, EraseTwentySeventh) {
  containers::Map<int, int> m = {{20, 4}, {10, 3}, {4, 3},  {2, 2},
                                 {5, 2},  {3, 1},  {14, 2}, {17, 2},
                                 {12, 2}, {15, 2}, {11, 1}, {19, 1}};
  auto it = m.begin();
  m.erase(it);
  it = m.begin();
  m.erase(it);
  it = m.begin();
  m.erase(it);
  it = m.begin();
  m.erase(it);
  it = m.begin();
  m.erase(it);
  it = m.begin();
  m.erase(it);
  it = m.begin();
  m.erase(it);
  it = m.begin();
  m.erase(it);
  it = m.begin();
  m.erase(it);
  it = m.begin();
  m.erase(it);
  it = m.begin();
  m.erase(it);
  it = m.begin();
  m.erase(it);
  ASSERT_EQ(m.size(), 0u);
}

TEST(TestMapErase, EraseTwentyEighth) {
  containers::Map<std::string, int> m{{"this", 1}, {"sentence", 2},
                                      {"is", 3},   {"not", 4},
                                      {"a", 5},    {"word", 6}};
  auto it = m.begin();
  it++;
  m.erase(it);
  ASSERT_EQ(m["this"], 1);
  ASSERT_EQ(m["sentence"], 2);
  ASSERT_EQ(m["not"], 4);
  ASSERT_EQ(m["a"], 5);
  ASSERT_EQ(m["word"], 6);
}

TEST(TestMapErase, TestMapEraseTwentyNinth) {
  containers::Map<int, int> m = {{20, 4}, {10, 3}, {4, 3},  {2, 2},  {5, 2},
                                 {3, 1},  {14, 2}, {17, 2}, {12, 2}, {15, 2},
                                 {11, 1}, {19, 1}, {25, 6}};
  auto it = m.end();
  it--;
  m.erase(it);
  it = m.end();
  it--;
  m.erase(it);
  ASSERT_EQ(m.size(), 11u);
  ASSERT_EQ(m[10], 3);
  ASSERT_EQ(m[4], 3);
  ASSERT_EQ(m[2], 2);
  ASSERT_EQ(m[5], 2);
  ASSERT_EQ(m[3], 1);
  ASSERT_EQ(m[12], 2);
  ASSERT_EQ(m[15], 2);
  ASSERT_EQ(m[11], 1);
  ASSERT_EQ(m[19], 1);
}

TEST(TestMapErase, TestMapEraseThirtieth) {
  containers::Map<int, int> m = {
      {30, 4}, {10, 3}, {4, 3},  {2, 2},  {5, 2},  {3, 1},  {12, 2}, {15, 2},
      {11, 2}, {20, 2}, {25, 1}, {18, 1}, {13, 5}, {14, 6}, {21, 1}, {17, 7}};
  auto it = m.end();
  it--;
  it--;
  m.erase(it);
  ASSERT_EQ(m.size(), 15u);
  ASSERT_EQ(m[30], 4);
  ASSERT_EQ(m[10], 3);
  ASSERT_EQ(m[4], 3);
  ASSERT_EQ(m[2], 2);
  ASSERT_EQ(m[5], 2);
  ASSERT_EQ(m[3], 1);
  ASSERT_EQ(m[12], 2);
  ASSERT_EQ(m[15], 2);
  ASSERT_EQ(m[11], 2);
  ASSERT_EQ(m[20], 2);
  ASSERT_EQ(m[17], 7);
  ASSERT_EQ(m[18], 1);
  ASSERT_EQ(m[13], 5);
  ASSERT_EQ(m[14], 6);
  ASSERT_EQ(m[21], 1);
}

TEST(TestMapErase, TestMapEraseThirtiethFirst) {
  containers::Map<int, int> m = {{30, 4}};
  auto it = m.begin();
  m.erase(it);
  ASSERT_EQ(m.size(), 0u);
}

TEST(TestMapErase, TestMapEraseThirtiethSecond) {
  containers::Map<int, int> m = {{30, 4}};
  auto it = m.end();
  it--;
  m.erase(it);
  ASSERT_EQ(m.size(), 0u);
  it = m.end();
  m.erase(it);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
