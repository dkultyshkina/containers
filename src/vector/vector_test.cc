#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "../containers.h"

TEST(TestVectorConstructor, ConstructorFirst) {
  containers::Vector<int> V = {1, 2, 3, 4, 5};
  std::vector<int> V2 = {1, 2, 3, 4, 5};
  ASSERT_EQ(V2.at(0), V.at(0));
  ASSERT_EQ(V2.at(1), V.at(1));
  ASSERT_EQ(V2.at(2), V.at(2));
  ASSERT_EQ(V2.at(3), V.at(3));
  ASSERT_EQ(V2.at(4), V.at(4));
}

TEST(TestVectorConstructor, ConstructorSecond) {
  containers::Vector<int> V;
  std::vector<int> V2;
  ASSERT_EQ(V2.size(), V.size());
  ASSERT_EQ(V2.capacity(), V.capacity());
}

TEST(TestVectorConstructor, ConstructorThird) {
  containers::Vector<int> V = {1, 2, 3, 4, 5};
  containers::Vector<int> V3(V);
  std::vector<int> V2 = {1, 2, 3, 4, 5};
  std::vector<int> V4(V2);
  ASSERT_EQ(V3.size(), V4.size());
  ASSERT_EQ(V3.capacity(), V4.capacity());
  ASSERT_EQ(V3[0], V4[0]);
  ASSERT_EQ(V3[1], V4[1]);
  ASSERT_EQ(V3[2], V4[2]);
  ASSERT_EQ(V3[3], V4[3]);
  ASSERT_EQ(V3[4], V4[4]);
}

TEST(TestVectorConstructor, ConstructorFourth) {
  containers::Vector<int> V = {1, 2, 3, 4, 5};
  containers::Vector<int> V3(std::move(V));
  std::vector<int> V2 = {1, 2, 3, 4, 5};
  std::vector<int> V4(std::move(V2));
  ASSERT_EQ(V3.size(), V4.size());
  ASSERT_EQ(V3.capacity(), V4.capacity());
  ASSERT_EQ(V3[0], V4[0]);
  ASSERT_EQ(V3[1], V4[1]);
  ASSERT_EQ(V3[2], V4[2]);
  ASSERT_EQ(V3[3], V4[3]);
  ASSERT_EQ(V3[4], V4[4]);
}

TEST(TestVectorConstructor, ConstructorSixth) {
  containers::Vector<int> V(5);
  std::vector<int> V2(5);
  ASSERT_EQ(V.size(), V2.size());
  ASSERT_EQ(V.capacity(), V2.capacity());
}

TEST(TestVectorConstructor, ConstructorSeventh) {
  containers::Vector<std::string> V = {"a", "b", "c", "d", "f"};
  containers::Vector<std::string> V3(std::move(V));
  std::vector<std::string> V2 = {"a", "b", "c", "d", "f"};
  ;
  std::vector<std::string> V4(std::move(V2));
  ASSERT_EQ(V3.size(), V4.size());
  ASSERT_EQ(V3.capacity(), V4.capacity());
  ASSERT_EQ(V3[0], V4[0]);
  ASSERT_EQ(V3[1], V4[1]);
  ASSERT_EQ(V3[2], V4[2]);
  ASSERT_EQ(V3[3], V4[3]);
  ASSERT_EQ(V3[4], V4[4]);
}

TEST(TestVectorConstructor, ConstructorEighth) {
  containers::Vector<std::string> V = {"a", "b", "c", "d", "f"};
  containers::Vector<std::string> V3(V);
  std::vector<std::string> V2 = {"a", "b", "c", "d", "f"};
  ;
  std::vector<std::string> V4(V2);
  ASSERT_EQ(V3.size(), V4.size());
  ASSERT_EQ(V3.capacity(), V4.capacity());
  ASSERT_EQ(V3[0], V4[0]);
  ASSERT_EQ(V3[1], V4[1]);
  ASSERT_EQ(V3[2], V4[2]);
  ASSERT_EQ(V3[3], V4[3]);
  ASSERT_EQ(V3[4], V4[4]);
}

TEST(TestVectorConstructor, ConstructorNinth) {
  containers::Vector<std::string> V = {"a", "b", "c", "d", "f"};
  containers::Vector<std::string> V3(std::move(V));
  std::vector<std::string> V2 = {"a", "b", "c", "d", "f"};
  ;
  std::vector<std::string> V4(std::move(V2));
  ASSERT_EQ(V3.size(), V4.size());
  ASSERT_EQ(V3.capacity(), V4.capacity());
  ASSERT_EQ(V3[0], V4[0]);
  ASSERT_EQ(V3[1], V4[1]);
  ASSERT_EQ(V3[2], V4[2]);
  ASSERT_EQ(V3[3], V4[3]);
  ASSERT_EQ(V3[4], V4[4]);
}

TEST(TestVectorConstructor, ConstructorTenth) {
  containers::Vector<std::string> V = {"a", "b", "c", "d", "f"};
  std::vector<std::string> V2 = {"a", "b", "c", "d", "f"};
  ;
  ASSERT_EQ(V.size(), V2.size());
  ASSERT_EQ(V.capacity(), V2.capacity());
  ASSERT_EQ(V[0], V2[0]);
  ASSERT_EQ(V[1], V2[1]);
  ASSERT_EQ(V[2], V2[2]);
  ASSERT_EQ(V[3], V2[3]);
  ASSERT_EQ(V[4], V2[4]);
}

TEST(TestVectorInsert, InsertFirst) {
  containers::Vector<int> V = {1, 2, 3, 4, 5};
  auto it = V.begin();
  it++;
  it++;
  V.insert(it, 200);
  std::vector<int> V2 = {1, 2, 3, 4, 5};
  auto iter = V2.begin();
  iter++;
  iter++;
  V2.insert(iter, 200);
  ASSERT_EQ(V2.at(0), V.at(0));
  ASSERT_EQ(V2.at(1), V.at(1));
  ASSERT_EQ(V2.at(2), V.at(2));
  ASSERT_EQ(V2.at(3), V.at(3));
  ASSERT_EQ(V2.at(4), V.at(4));
}

TEST(TestVectorInsert, InsertSecond) {
  containers::Vector<int> V = {1, 2, 3, 4, 5};
  auto it = V.end();
  it--;
  V.insert(it, 200);
  std::vector<int> V2 = {1, 2, 3, 4, 5};
  auto iter = V2.end();
  iter--;
  V2.insert(iter, 200);
  ASSERT_EQ(V2.at(0), V.at(0));
  ASSERT_EQ(V2.at(1), V.at(1));
  ASSERT_EQ(V2.at(2), V.at(2));
  ASSERT_EQ(V2.at(3), V.at(3));
  ASSERT_EQ(V2.at(4), V.at(4));
}

TEST(TestVectorInsert, InsertThird) {
  containers::Vector<int> V;
  V.push_back(2);
  V.push_back(1);
  V.push_back(3);
  V.push_back(4);
  auto it = V.begin();
  it++;
  V.insert(it, 200);
  std::vector<int> V2;
  V2.push_back(2);
  V2.push_back(1);
  V2.push_back(3);
  V2.push_back(4);
  auto iter = V2.begin();
  iter++;
  V2.insert(iter, 200);
  ASSERT_EQ(V2.at(0), V.at(0));
  ASSERT_EQ(V2.at(1), V.at(1));
  ASSERT_EQ(V2.at(2), V.at(2));
  ASSERT_EQ(V2.at(3), V.at(3));
  ASSERT_EQ(V2.at(4), V.at(4));
}

TEST(TestVectorInsert, InsertFourth) {
  containers::Vector<int> V;
  V.push_back(2);
  V.push_back(3);
  V.push_back(4);
  V.push_back(5);
  V.push_back(8);
  V.push_back(4);
  auto it = V.begin();
  V.insert(it, 200);
  std::vector<int> V2;
  V2.push_back(2);
  V2.push_back(3);
  V2.push_back(4);
  V2.push_back(5);
  V2.push_back(8);
  V2.push_back(4);
  auto iter = V2.begin();
  V2.insert(iter, 200);
  ASSERT_EQ(V2.at(0), V.at(0));
  ASSERT_EQ(V2.at(1), V.at(1));
  ASSERT_EQ(V2.at(2), V.at(2));
  ASSERT_EQ(V2.at(3), V.at(3));
  ASSERT_EQ(V2.at(4), V.at(4));
  ASSERT_EQ(V2.at(5), V.at(5));
  ASSERT_EQ(V2.at(6), V.at(6));
}

TEST(TestVectorInsert, InsertFifth) {
  containers::Vector<int> V = {1, 2, 3, 4, 5};
  auto it = V.begin();
  for (size_t j = 0; j < V.size(); ++j) {
    it++;
  }
  V.insert(it, 200);
  std::vector<int> V2 = {1, 2, 3, 4, 5};
  auto iter = V2.begin();
  for (size_t j = 0; j < V2.size(); ++j) {
    iter++;
  }
  V2.insert(iter, 200);
  ASSERT_EQ(V2.at(0), V.at(0));
  ASSERT_EQ(V2.at(1), V.at(1));
  ASSERT_EQ(V2.at(2), V.at(2));
  ASSERT_EQ(V2.at(3), V.at(3));
  ASSERT_EQ(V2.at(4), V.at(4));
}

TEST(TestVectorInsert, InsertSixth) {
  containers::Vector<std::string> V = {"a", "b", "c", "d", "f"};
  auto it = V.begin();
  for (size_t j = 0; j < V.size(); ++j) {
    it++;
  }
  V.insert(it, "e");
  std::vector<std::string> V2 = {"a", "b", "c", "d", "f"};
  auto iter = V2.begin();
  for (size_t j = 0; j < V2.size(); ++j) {
    iter++;
  }
  V2.insert(iter, "e");
  ASSERT_EQ(V2.at(0), V.at(0));
  ASSERT_EQ(V2.at(1), V.at(1));
  ASSERT_EQ(V2.at(2), V.at(2));
  ASSERT_EQ(V2.at(3), V.at(3));
  ASSERT_EQ(V2.at(4), V.at(4));
}

TEST(TestVectorInsert, InsertSeventh) {
  containers::Vector<char> V = {'a', 'b', 'c', 'd', 'f'};
  auto it = V.end();
  it--;
  V.insert(it, 'e');
  std::vector<char> V2 = {'a', 'b', 'c', 'd', 'f'};
  auto iter = V2.end();
  iter--;
  V2.insert(iter, 'e');
  ASSERT_EQ(V2.at(0), V.at(0));
  ASSERT_EQ(V2.at(1), V.at(1));
  ASSERT_EQ(V2.at(2), V.at(2));
  ASSERT_EQ(V2.at(3), V.at(3));
  ASSERT_EQ(V2.at(4), V.at(4));
}

TEST(TestVectorShrinkToFit, ShrinkToFitFirst) {
  containers::Vector<int> V;
  V.resize(100);
  V.shrink_to_fit();
  std::vector<int> V2;
  V2.resize(100);
  V2.shrink_to_fit();
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.size(), V.size());
}

TEST(TestVectorShrinkToFit, ShrinkToFitSecond) {
  containers::Vector<int> V;
  V.resize(100);
  V.resize(50);
  V.shrink_to_fit();
  std::vector<int> V2;
  V2.resize(100);
  V2.resize(50);
  V2.shrink_to_fit();
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.size(), V.size());
}

TEST(TestVectorShrinkToFit, ShrinkToFitThird) {
  containers::Vector<int> V;
  V.resize(0);
  V.resize(100);
  V.resize(50);
  V.shrink_to_fit();
  V.shrink_to_fit();
  std::vector<int> V2;
  V2.resize(0);
  V2.resize(100);
  V2.resize(50);
  V2.shrink_to_fit();
  V2.shrink_to_fit();
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.size(), V.size());
}

TEST(TestVectorPushBack, PushBackFirst) {
  containers::Vector<int> V = {1, 2, 3, 4, 5};
  V.push_back(6);
  std::vector<int> V2 = {1, 2, 3, 4, 5};
  V2.push_back(6);
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.size(), V.size());
  ASSERT_EQ(V2.at(0), V.at(0));
  ASSERT_EQ(V2.at(1), V.at(1));
  ASSERT_EQ(V2.at(2), V.at(2));
  ASSERT_EQ(V2.at(3), V.at(3));
  ASSERT_EQ(V2.at(4), V.at(4));
  ASSERT_EQ(V2.at(5), V.at(5));
}

TEST(TestVectorPushBack, PushBackSecond) {
  containers::Vector<int> V;
  V.push_back(6);
  std::vector<int> V2;
  V2.push_back(6);
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.size(), V.size());
  ASSERT_EQ(V2.at(0), V.at(0));
}

TEST(TestVectorPushBack, PushBackThird) {
  containers::Vector<int> V;
  V.push_back(6);
  V.push_back(5);
  V.push_back(4);
  V.push_back(3);
  std::vector<int> V2;
  V2.push_back(6);
  V2.push_back(5);
  V2.push_back(4);
  V2.push_back(3);
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.at(1), V.at(1));
  ASSERT_EQ(V2.at(2), V.at(2));
  ASSERT_EQ(V2.at(3), V.at(3));
  ASSERT_EQ(V2.size(), V.size());
  ASSERT_EQ(V2.at(0), V.at(0));
}

TEST(TestVectorPushBack, PushBackFourth) {
  containers::Vector<char> V;
  V.push_back('a');
  V.push_back('b');
  V.push_back('c');
  V.push_back('d');
  std::vector<char> V2;
  V2.push_back('a');
  V2.push_back('b');
  V2.push_back('c');
  V2.push_back('d');
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.at(1), V.at(1));
  ASSERT_EQ(V2.at(2), V.at(2));
  ASSERT_EQ(V2.at(3), V.at(3));
  ASSERT_EQ(V2.size(), V.size());
  ASSERT_EQ(V2.at(0), V.at(0));
}

TEST(TestVectorPushBack, PushBackFifth) {
  containers::Vector<std::string> V = {"a", "b", "c", "d", "f"};
  V.push_back("e");
  std::vector<std::string> V2 = {"a", "b", "c", "d", "f"};
  V2.push_back("e");
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.size(), V.size());
  ASSERT_EQ(V2.at(0), V.at(0));
  ASSERT_EQ(V2.at(1), V.at(1));
  ASSERT_EQ(V2.at(2), V.at(2));
  ASSERT_EQ(V2.at(3), V.at(3));
  ASSERT_EQ(V2.at(4), V.at(4));
}

TEST(TestVectorPopBack, PopBackFirst) {
  containers::Vector<int> V = {1, 2, 3, 4, 5, 89};
  V.pop_back();
  std::vector<int> V2 = {1, 2, 3, 4, 5, 89};
  V2.pop_back();
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.size(), V.size());
  ASSERT_EQ(V2.at(0), V.at(0));
  ASSERT_EQ(V2.at(1), V.at(1));
  ASSERT_EQ(V2.at(2), V.at(2));
  ASSERT_EQ(V2.at(3), V.at(3));
  ASSERT_EQ(V2.at(4), V.at(4));
}

TEST(TestVectorPopBack, PopBackSecond) {
  containers::Vector<int> V = {1, 2, 3, 4};
  V.pop_back();
  std::vector<int> V2 = {1, 2, 3, 4};
  V2.pop_back();
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.size(), V.size());
  ASSERT_EQ(V2.at(0), V.at(0));
  ASSERT_EQ(V2.at(1), V.at(1));
  ASSERT_EQ(V2.at(2), V.at(2));
}

TEST(TestVectorPopBack, PopBackThird) {
  containers::Vector<int> V = {1, 2, 3, 4, 5};
  V.pop_back();
  std::vector<int> V2 = {1, 2, 3, 4, 5};
  V2.pop_back();
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.size(), V.size());
  ASSERT_EQ(V2.at(0), V.at(0));
  ASSERT_EQ(V2.at(1), V.at(1));
  ASSERT_EQ(V2.at(2), V.at(2));
  ASSERT_EQ(V2.at(3), V.at(3));
}

TEST(TestVectorPopBack, PopBackFourth) {
  containers::Vector<int> V;
  V.push_back(6);
  V.push_back(5);
  V.push_back(4);
  V.push_back(3);
  std::vector<int> V2;
  V2.push_back(6);
  V2.push_back(5);
  V2.push_back(4);
  V2.push_back(3);

  V.pop_back();
  V2.pop_back();
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.size(), V.size());
  ASSERT_EQ(V2.at(0), V.at(0));
  ASSERT_EQ(V2.at(1), V.at(1));
  ASSERT_EQ(V2.at(2), V.at(2));
}

TEST(TestVectorPopBack, PopBackFifth) {
  containers::Vector<int> V;
  std::vector<int> V2;
  V.pop_back();
  V2.pop_back();
  ASSERT_EQ(V2.capacity(), V.capacity());
}

TEST(TestVectorPopBack, PopBackSixth) {
  containers::Vector<int> V = {1};
  std::vector<int> V2 = {1};
  V.pop_back();
  V2.pop_back();
  ASSERT_EQ(V2.capacity(), V.capacity());
}

TEST(TestVectorPopBack, PopBackSeveth) {
  containers::Vector<char> V;
  V.push_back('a');
  V.push_back('b');
  V.push_back('c');
  V.push_back('d');
  std::vector<char> V2;
  V2.push_back('a');
  V2.push_back('b');
  V2.push_back('c');
  V2.push_back('d');
  V.pop_back();
  V2.pop_back();
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.at(1), V.at(1));
  ASSERT_EQ(V2.at(2), V.at(2));
  ASSERT_EQ(V2.size(), V.size());
  ASSERT_EQ(V2.at(0), V.at(0));
}

TEST(TestVectorPopBack, PopBackEighth) {
  containers::Vector<char> V = {'a', 'b', 'c', 'd', 'f'};
  std::vector<char> V2 = {'a', 'b', 'c', 'd', 'f'};
  V.pop_back();
  V2.pop_back();
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.size(), V.size());
  ASSERT_EQ(V2.at(0), V.at(0));
  ASSERT_EQ(V2.at(1), V.at(1));
  ASSERT_EQ(V2.at(2), V.at(2));
  ASSERT_EQ(V2.at(3), V.at(3));
}

TEST(TestVectorClear, ClearFirst) {
  containers::Vector<int> V = {1, 2, 3, 4, 5};
  V.clear();
  std::vector<int> V2 = {1, 2, 3, 4, 5};
  V2.clear();
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.size(), V.size());
}

TEST(TestVectorClear, ClearSecond) {
  containers::Vector<int> V = {4848, 344, 4565, 899, 22, -4505};
  V.clear();
  std::vector<int> V2 = {4848, 344, 4565, 899, 22, -4505};
  V2.clear();
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.size(), V.size());
}

TEST(TestVectorClear, ClearThird) {
  containers::Vector<int> V;
  V.clear();
  std::vector<int> V2;
  V2.clear();
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.size(), V.size());
}

TEST(TestVectorErase, EraseFirst) {
  containers::Vector<int> V = {1};
  V.erase(V.begin());
  std::vector<int> V2 = {1};
  V2.erase(V2.begin());
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.size(), V.size());
}

TEST(TestVectorErase, EraseSecond) {
  containers::Vector<int> V = {1, 2, 3, 4, 5};
  auto it = V.end();
  it--;
  it--;
  it--;
  V.erase(it);
  std::vector<int> V2 = {1, 2, 3, 4, 5};
  auto iter = V2.end();
  iter--;
  iter--;
  iter--;
  V2.erase(iter);
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.size(), V.size());
  ASSERT_EQ(V2.at(0), V.at(0));
  ASSERT_EQ(V2.at(1), V.at(1));
  ASSERT_EQ(V2.at(2), V.at(2));
  ASSERT_EQ(V2.at(3), V.at(3));
}

TEST(TestVectorErase, EraseThird) {
  containers::Vector<int> V = {1, 2, 3, 4, 5};
  auto it = V.end();
  it--;
  V.erase(it);
  std::vector<int> V2 = {1, 2, 3, 4, 5};
  auto iter = V2.end();
  iter--;
  V2.erase(iter);
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.size(), V.size());
  ASSERT_EQ(V2.at(0), V.at(0));
  ASSERT_EQ(V2.at(1), V.at(1));
  ASSERT_EQ(V2.at(2), V.at(2));
  ASSERT_EQ(V2.at(3), V.at(3));
}

TEST(TestVectorErase, EraseFourth) {
  containers::Vector<int> V = {1, 2, 3, 4, 5};
  auto it = V.end();
  it--;
  it--;
  V.erase(it);
  std::vector<int> V2 = {1, 2, 3, 4, 5};
  auto iter = V2.end();
  iter--;
  iter--;
  V2.erase(iter);
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.size(), V.size());
  ASSERT_EQ(V2.at(0), V.at(0));
  ASSERT_EQ(V2.at(1), V.at(1));
  ASSERT_EQ(V2.at(2), V.at(2));
  ASSERT_EQ(V2.at(3), V.at(3));
}

TEST(TestVectorErase, EraseSixth) {
  containers::Vector<std::string> V = {"a", "b", "c", "d", "f"};
  V.erase(V.begin());
  std::vector<std::string> V2 = {"a", "b", "c", "d", "f"};
  V2.erase(V2.begin());
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.size(), V.size());
  ASSERT_EQ(V2.at(0), V.at(0));
  ASSERT_EQ(V2.at(1), V.at(1));
  ASSERT_EQ(V2.at(2), V.at(2));
  ASSERT_EQ(V2.at(3), V.at(3));
}

TEST(TestVectorErase, EraseSeventh) {
  containers::Vector<std::string> V = {"a", "b", "c", "d", "f"};
  auto it = V.erase(V.begin());
  std::vector<std::string> V2 = {"a", "b", "c", "d", "f"};
  auto iter = V2.erase(V2.begin());
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.size(), V.size());
  ASSERT_EQ(*iter, *it);
}

TEST(TestVectorFront, Front) {
  containers::Vector<int> V = {1, 2, 3};
  auto result_1 = V.front();
  std::vector<int> V2 = {1, 2, 3};
  auto result_2 = V2.front();
  ASSERT_EQ(result_1, result_2);
}

TEST(TestVectorBack, Back) {
  containers::Vector<int> V = {1, 2, 3};
  auto result_1 = V.back();
  std::vector<int> V2 = {1, 2, 3};
  auto result_2 = V2.back();
  ASSERT_EQ(result_1, result_2);
}

TEST(TestVectorData, DataFirst) {
  containers::Vector<int> V = {1, 2, 3};
  auto result_1 = V.data();
  std::vector<int> V2 = {1, 2, 3};
  auto result_2 = V2.data();
  ASSERT_NE(result_1, nullptr);
  ASSERT_NE(result_2, nullptr);
}

TEST(TestVectorData, DataSecond) {
  containers::Vector<int> V;
  auto result_1 = V.data();
  std::vector<int> V2;
  auto result_2 = V2.data();
  ASSERT_EQ(result_1, nullptr);
  ASSERT_EQ(result_2, nullptr);
}

TEST(TestVectorEmpty, EmptyFirst) {
  containers::Vector<int> V = {1, 2, 3};
  auto result_1 = V.empty();
  std::vector<int> V2 = {1, 2, 3};
  auto result_2 = V2.empty();
  ASSERT_EQ(result_1, false);
  ASSERT_EQ(result_2, false);
}

TEST(TestVectorEmpty, EmptySecond) {
  containers::Vector<int> V;
  auto result_1 = V.empty();
  std::vector<int> V2;
  auto result_2 = V2.empty();
  ASSERT_EQ(result_1, true);
  ASSERT_EQ(result_2, true);
}

TEST(TestVectorSize, SizeFirst) {
  containers::Vector<int> V = {1, 2, 3};
  auto result_1 = V.size();
  std::vector<int> V2 = {1, 2, 3};
  auto result_2 = V2.size();
  ASSERT_EQ(result_1, result_2);
}

TEST(TestVectorSize, SizeSecond) {
  containers::Vector<int> V;
  auto result_1 = V.size();
  std::vector<int> V2;
  auto result_2 = V2.size();
  ASSERT_EQ(result_1, result_2);
}

TEST(TestVectorCapacity, CapacityFirst) {
  containers::Vector<int> V = {1, 2, 3};
  auto result_1 = V.capacity();
  std::vector<int> V2 = {1, 2, 3};
  auto result_2 = V2.capacity();
  ASSERT_EQ(result_1, result_2);
}

TEST(TestVectorCapacity, CapacitySecond) {
  containers::Vector<int> V;
  auto result_1 = V.capacity();
  std::vector<int> V2;
  auto result_2 = V2.capacity();
  ASSERT_EQ(result_1, result_2);
}

TEST(TestVectorMaxSize, MaxSizeFirst) {
  containers::Vector<int> V = {1, 2, 3};
  auto result_1 = V.max_size();
  std::vector<int> V2 = {1, 2, 3};
  auto result_2 = V2.max_size();
  ASSERT_EQ(result_1, result_2);
}

TEST(TestVectorMaxSize, MaxSizeSecond) {
  containers::Vector<int> V;
  auto result_1 = V.max_size();
  std::vector<int> V2;
  auto result_2 = V2.max_size();
  ASSERT_EQ(result_1, result_2);
}

TEST(TestVectorMaxSize, MaxSizeThird) {
  containers::Vector<std::string> V = {"a", "b", "c", "d", "f"};
  std::vector<std::string> V2 = {"a", "b", "c", "d", "f"};
  auto result_1 = V.max_size();
  auto result_2 = V2.max_size();
  ASSERT_EQ(result_1, result_2);
}

TEST(TestVectorReserve, ReserveFirst) {
  containers::Vector<int> V = {1, 2, 3};
  V.reserve(6);
  std::vector<int> V2 = {1, 2, 3};
  V2.reserve(6);
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.size(), V.size());
}

TEST(TestVectorReserve, ReserveSecond) {
  containers::Vector<int> V;
  V.reserve(5);
  std::vector<int> V2;
  V2.reserve(5);
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.size(), V.size());
}

TEST(TestVectorSwap, SwapFirst) {
  containers::Vector<int> V = {1, 2, 3};
  containers::Vector<int> V3 = {3, 2, 1};
  V.swap(V3);
  std::vector<int> V2 = {1, 2, 3};
  std::vector<int> V4 = {3, 2, 1};
  V2.swap(V4);
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V3.size(), V4.size());
  ASSERT_EQ(*(V.begin()), *(V2.begin()));
  ASSERT_EQ(*(V3.begin()), *(V4.begin()));
}

TEST(TestVectorSwap, SwapSecond) {
  containers::Vector<int> V = {1, 2};
  containers::Vector<int> V3 = {4, 5, 6};
  V.swap(V3);
  std::vector<int> V2 = {1, 2};
  std::vector<int> V4 = {4, 5, 6};
  V2.swap(V4);
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V3.size(), V4.size());
  ASSERT_EQ(*(V.begin()), *(V2.begin()));
  ASSERT_EQ(*(V3.begin()), *(V4.begin()));
}

TEST(TestVectorSwap, SwapThird) {
  containers::Vector<int> V = {1, 2, 3, 6, 7, 3, 6, 2, 4};
  containers::Vector<int> V3 = {3};
  V.swap(V3);
  std::vector<int> V2 = {1, 2, 3, 6, 7, 3, 6, 2, 4};
  std::vector<int> V4 = {3};
  V2.swap(V4);
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V3.size(), V4.size());
  ASSERT_EQ(*(V.begin()), *(V2.begin()));
  ASSERT_EQ(*(V3.begin()), *(V4.begin()));
}

TEST(TestVectorSwap, SwapFourth) {
  containers::Vector<int> V = {1};
  containers::Vector<int> V3 = {4};
  V.swap(V3);
  std::vector<int> V2 = {1};
  std::vector<int> V4 = {4};
  V2.swap(V4);
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V3.size(), V4.size());
  ASSERT_EQ(*(V.begin()), *(V2.begin()));
  ASSERT_EQ(*(V3.begin()), *(V4.begin()));
}

TEST(TestVectorSwap, SwapFifth) {
  containers::Vector<std::string> V = {"a", "b", "c", "d", "f"};
  containers::Vector<std::string> V3 = {"is", "not", "one", "word"};
  V.swap(V3);
  std::vector<std::string> V2 = {"a", "b", "c", "d", "f"};
  std::vector<std::string> V4 = {"is", "not", "one", "word"};
  V2.swap(V4);
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V3.size(), V4.size());
  ASSERT_EQ(*(V.begin()), *(V2.begin()));
  ASSERT_EQ(*(V3.begin()), *(V4.begin()));
}

TEST(TestVectorSwap, SwapSixth) {
  containers::Vector<std::string> V3 = {"a", "b", "c", "d", "f"};
  containers::Vector<std::string> V = {"is", "not", "one", "word"};
  V.swap(V3);
  std::vector<std::string> V4 = {"a", "b", "c", "d", "f"};
  std::vector<std::string> V2 = {"is", "not", "one", "word"};
  V2.swap(V4);
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V3.size(), V4.size());
  ASSERT_EQ(*(V.begin()), *(V2.begin()));
  ASSERT_EQ(*(V3.begin()), *(V4.begin()));
}

TEST(TestVectorOperator, OperatorFirst) {
  containers::Vector<int> V = {4, 6, 8, 10};
  containers::Vector<int> V3 = {2, 5};
  V = std::move(V3);
  std::vector<int> V2 = {4, 6, 8, 10};
  std::vector<int> V4 = {2, 5};
  V2 = std::move(V4);
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.size(), V.size());
  ASSERT_EQ(*(V.begin()), *(V2.begin()));
  ASSERT_EQ(V[1], V2[1]);
}

TEST(TestVectorOperator, OperatorSecond) {
  containers::Vector<int> V = {2, 5};
  containers::Vector<int> V3 = {4, 6, 8, 10};
  V = std::move(V3);
  std::vector<int> V2 = {2, 5};
  std::vector<int> V4 = {4, 6, 8, 10};
  V2 = std::move(V4);
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.size(), V.size());
  ASSERT_EQ(*(V.begin()), *(V2.begin()));
  ASSERT_EQ(V[1], V2[1]);
  ASSERT_EQ(V[2], V2[2]);
  ASSERT_EQ(V[3], V2[3]);
}

TEST(TestVectorOperator, OperatorThird) {
  containers::Vector<int> V = {1, 2, 3, 6, 7, 3, 6, 2};
  containers::Vector<int> V3 = {1, 2, 3, 6, 7, 3, 6, 2, 4};
  V = std::move(V3);
  std::vector<int> V2 = {1, 2, 3, 6, 7, 3, 6, 2};
  std::vector<int> V4 = {1, 2, 3, 6, 7, 3, 6, 2, 4};
  V2 = std::move(V4);
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.size(), V.size());
  ASSERT_EQ(*(V.begin()), *(V2.begin()));
  ASSERT_EQ(V[1], V2[1]);
  ASSERT_EQ(V[2], V2[2]);
  ASSERT_EQ(V[3], V2[3]);
}

TEST(TestVectorOperator, OperatorFourth) {
  containers::Vector<int> V = {4, 6, 8, 10};
  containers::Vector<int> V3 = {2, 5};
  V = V3;
  std::vector<int> V2 = {4, 6, 8, 10};
  std::vector<int> V4 = {2, 5};
  V2 = V4;
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.size(), V.size());
  ASSERT_EQ(*(V.begin()), *(V2.begin()));
  ASSERT_EQ(V[1], V2[1]);
}

TEST(TestVectorOperator, OperatorFifth) {
  containers::Vector<int> V = {2, 5};
  containers::Vector<int> V3 = {4, 6, 8, 10};
  V = V3;
  std::vector<int> V2 = {2, 5};
  std::vector<int> V4 = {4, 6, 8, 10};
  V2 = V4;
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.size(), V.size());
  ASSERT_EQ(*(V.begin()), *(V2.begin()));
  ASSERT_EQ(V[1], V2[1]);
  ASSERT_EQ(V[2], V2[2]);
  ASSERT_EQ(V[3], V2[3]);
}

TEST(TestVectorOperator, OperatorSixth) {
  containers::Vector<int> V = {1, 2, 3, 6, 7, 3, 6, 2};
  containers::Vector<int> V3 = {1, 2, 3, 6, 7, 3, 6, 2, 4};
  V = V3;
  std::vector<int> V2 = {1, 2, 3, 6, 7, 3, 6, 2};
  std::vector<int> V4 = {1, 2, 3, 6, 7, 3, 6, 2, 4};
  V2 = V4;
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.size(), V.size());
  ASSERT_EQ(*(V.begin()), *(V2.begin()));
  ASSERT_EQ(V[1], V2[1]);
  ASSERT_EQ(V[2], V2[2]);
  ASSERT_EQ(V[3], V2[3]);
}

TEST(TestVectorOperator, OperatorSeventh) {
  containers::Vector<std::string> V = {"a", "b", "c", "d", "f"};
  containers::Vector<std::string> V3 = {"it", "is", "not", "one", "word"};
  V = V3;
  std::vector<std::string> V2 = {"a", "b", "c", "d", "f"};
  std::vector<std::string> V4 = {"it", "is", "not", "one", "word"};
  V2 = V4;
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.size(), V.size());
  ASSERT_EQ(*(V.begin()), *(V2.begin()));
  ASSERT_EQ(V[1], V2[1]);
  ASSERT_EQ(V[2], V2[2]);
  ASSERT_EQ(V[3], V2[3]);
}

TEST(TestVectorOperator, OperatorEighth) {
  containers::Vector<std::string> V = {"it", "is", "not", "one", "word"};
  containers::Vector<std::string> V3 = {"a", "b", "c", "d", "f"};
  V = V3;
  std::vector<std::string> V4 = {"a", "b", "c", "d", "f"};
  std::vector<std::string> V2 = {"it", "is", "not", "one", "word"};
  V2 = V4;
  ASSERT_EQ(V2.capacity(), V.capacity());
  ASSERT_EQ(V2.size(), V.size());
  ASSERT_EQ(*(V.begin()), *(V2.begin()));
  ASSERT_EQ(V[1], V2[1]);
  ASSERT_EQ(V[2], V2[2]);
  ASSERT_EQ(V[3], V2[3]);
}

TEST(TestVectorAt, At) {
  containers::Vector<int> V = {1, 2};
  std::vector<int> V2 = {1, 2};
  EXPECT_ANY_THROW(V.at(2));
  EXPECT_ANY_THROW(V2.at(7));
}

TEST(TestVectorAt, AtSecond) {
  containers::Vector<int> V = {1, 2};
  std::vector<int> V2 = {1, 2};
  ASSERT_EQ(V.at(1), V2.at(1));
  ASSERT_EQ(V.at(0), V2.at(0));
}

TEST(TestVectorBrackets, Brackets) {
  containers::Vector<int> V = {1, 2};
  EXPECT_ANY_THROW(V[4]);
}

TEST(TestVectorBrackets, BracketsSecond) {
  containers::Vector<int> V = {1, 2};
  std::vector<int> V2 = {1, 2};
  ASSERT_EQ(V[0], V2[0]);
  ASSERT_EQ(V[1], V2[1]);
}

TEST(TestVectorIterator, IteratorFirst) {
  containers::Vector<int> V = {1, 2};
  auto it = V.begin();
  std::vector<int> V2 = {1, 2};
  auto iter = V2.begin();
  ASSERT_EQ(it + 1, *(iter + 1));
}

TEST(TestVectorIterator, IteratorSecond) {
  containers::Vector<int> V = {1, 2};
  auto it = V.end();
  std::vector<int> V2 = {1, 2};
  auto iter = V2.end();
  ASSERT_EQ(it - 2, *(iter - 2));
}

TEST(TestVectorIterator, IteratorThird) {
  containers::Vector<int> V = {1, 2};
  auto it = V.end();
  --it;
  std::vector<int> V2 = {1, 2};
  auto iter = V2.end();
  --iter;
  ASSERT_EQ(*it, *(iter));
}

TEST(TestVectorIterator, IteratorFourth) {
  containers::Vector<int> V = {1, 2};
  auto it = V.begin();
  std::vector<int> V2 = {1, 2};
  auto iter = V2.begin();
  ASSERT_EQ(*it, *iter);
}

TEST(TestVectorIterator, IteratorFifth) {
  containers::Vector<std::string> V = {"it", "is", "not", "one", "word"};
  auto it = V.cbegin();
  it++;
  it++;
  it++;
  it++;
  std::vector<std::string> V2 = {"it", "is", "not", "one", "word"};
  auto iter = V2.cbegin();
  iter++;
  iter++;
  iter++;
  iter++;
  ASSERT_EQ(*it, *iter);
}

TEST(TestVectorIterator, IteratorSixth) {
  containers::Vector<int> V = {1, 2};
  auto it = V.begin();
  ++it;
  std::vector<int> V2 = {1, 2};
  auto iter = V2.begin();
  ++iter;
  ASSERT_EQ(*it, *iter);
}

TEST(TestVectorIterator, IteratorSeventh) {
  containers::Vector<int> V = {1, 2};
  containers::Vector<int> V2 = {1, 2};
  auto it = V.begin();
  auto it2 = V2.begin();
  std::vector<int> V3 = {1, 2};
  std::vector<int> V4 = {1, 2};
  auto iter = V3.begin();
  auto iter2 = V4.begin();
  ASSERT_EQ(it != it2, iter != iter2);
}

TEST(TestVectorIterator, IteratorEighth) {
  containers::Vector<int> V = {1, 2};
  containers::Vector<int> V2 = {1, 2};
  auto it = V.begin();
  auto it2 = V2.begin();
  std::vector<int> V3 = {1, 2};
  std::vector<int> V4 = {1, 2};
  auto iter = V3.begin();
  auto iter2 = V4.begin();
  ASSERT_EQ(it == it2, iter == iter2);
}

TEST(TestVectorIterator, IteratorNinth) {
  containers::Vector<int> V = {1, 2, 3, 4, 5, 7, 10};
  containers::Vector<int> V2 = {1, 2, 3, 4, 5, 7, 10};
  auto it = V.begin();
  it++;
  it++;
  it++;
  it--;
  auto iter = V2.begin();
  iter++;
  iter++;
  iter++;
  iter--;
  ASSERT_EQ(*it, *iter);
}

TEST(TestVectorIterator, IteratorTenth) {
  containers::Vector<int> V = {1, 2, 3, 4, 5};
  auto it = V.begin();
  auto it2 = V.begin();
  it2++;
  it2++;
  std::vector<int> V2 = {1, 2, 3, 4, 5};
  auto iter = V2.begin();
  auto iter2 = V2.begin();
  iter2++;
  iter2++;
  ASSERT_EQ(it < it2, iter < iter2);
}

TEST(TestVectorIterator, IteratorEleventh) {
  containers::Vector<int> V = {1, 2, 3, 4, 5};
  auto it = V.begin();
  auto it2 = V.begin();
  it2++;
  it2++;
  std::vector<int> V2 = {1, 2, 3, 4, 5};
  auto iter = V2.begin();
  auto iter2 = V2.begin();
  iter2++;
  iter2++;
  ASSERT_EQ(it > it2, iter > iter2);
}

TEST(TestVectorIterator, IteratorTwelfth) {
  containers::Vector<int> V = {1, 2, 3, 4, 5};
  auto it = V.begin();
  auto it2 = V.begin();
  it2++;
  it2++;
  it2++;
  std::vector<int> V2 = {1, 2, 3, 4, 5};
  auto iter = V2.begin();
  auto iter2 = V2.begin();
  iter2++;
  iter2++;
  iter2++;
  ASSERT_EQ(it <= it2, iter < iter2);
}

TEST(TestVectorIterator, IteratorThirteenth) {
  containers::Vector<int> V = {1, 2, 3, 4, 5};
  auto it = V.begin();
  auto it2 = V.begin();
  it2++;
  it2++;
  it2++;
  std::vector<int> V2 = {1, 2, 3, 4, 5};
  auto iter = V2.begin();
  auto iter2 = V2.begin();
  iter2++;
  iter2++;
  iter2++;
  ASSERT_EQ(it >= it2, iter >= iter2);
}

TEST(TestVectorIteratorConst, IteratorConstFirst) {
  containers::Vector<int> V = {1, 2};
  auto it = V.cbegin();
  std::vector<int> V2 = {1, 2};
  auto iter = V2.cbegin();
  ASSERT_EQ(it + 1, *(iter + 1));
}

TEST(TestVectorIteratorConst, IteratorConstSecond) {
  containers::Vector<int> V = {1, 2};
  auto it = V.cend();
  std::vector<int> V2 = {1, 2};
  auto iter = V2.cend();
  ASSERT_EQ(it - 2, *(iter - 2));
}

TEST(TestVectorIteratorConst, IteratorConstThird) {
  containers::Vector<int> V = {1, 2};
  auto it = V.cend();
  --it;
  std::vector<int> V2 = {1, 2};
  auto iter = V2.cend();
  --iter;
  ASSERT_EQ(*it, *(iter));
}

TEST(TestVectorIteratorConst, IteratorFourthConst) {
  containers::Vector<int> V = {1, 2};
  auto it = V.cbegin();
  std::vector<int> V2 = {1, 2};
  auto iter = V2.cbegin();
  ASSERT_EQ(*it, *iter);
}

TEST(TestVectorIteratorConst, IteratorFifthConst) {
  containers::Vector<std::string> V = {"it", "is", "not", "one", "word"};
  auto it = V.cbegin();
  it++;
  it++;
  it++;
  it++;
  std::vector<std::string> V2 = {"it", "is", "not", "one", "word"};
  auto iter = V2.cbegin();
  iter++;
  iter++;
  iter++;
  iter++;
  ASSERT_EQ(*it, *iter);
}

TEST(TestVectorIteratorConst, IteratorSixthConst) {
  containers::Vector<int> V = {1, 2};
  auto it = V.cbegin();
  ++it;
  std::vector<int> V2 = {1, 2};
  auto iter = V2.cbegin();
  ++iter;
  ASSERT_EQ(*it, *iter);
}

TEST(TestVectorIteratorConst, IteratorSeventhConst) {
  containers::Vector<int> V = {1, 2};
  containers::Vector<int> V2 = {1, 2};
  auto it = V.cbegin();
  auto it2 = V2.cbegin();
  std::vector<int> V3 = {1, 2};
  std::vector<int> V4 = {1, 2};
  auto iter = V3.cbegin();
  auto iter2 = V4.cbegin();
  ASSERT_EQ(it != it2, iter != iter2);
}

TEST(TestVectorIteratorConst, IteratorEighthConst) {
  containers::Vector<int> V = {1, 2};
  containers::Vector<int> V2 = {1, 2};
  auto it = V.cbegin();
  auto it2 = V2.cbegin();
  std::vector<int> V3 = {1, 2};
  std::vector<int> V4 = {1, 2};
  auto iter = V3.cbegin();
  auto iter2 = V4.cbegin();
  ASSERT_EQ(it == it2, iter == iter2);
}

TEST(TestVectorIteratorConst, IteratorNinthConst) {
  containers::Vector<int> V = {1, 2};
  containers::Vector<int> V2 = {3, 2};
  auto it = V.cbegin();
  auto it2 = V2.cbegin();
  std::vector<int> V3 = {1, 2};
  std::vector<int> V4 = {3, 2};
  auto iter = V3.cbegin();
  auto iter2 = V4.cbegin();
  it = it2;
  iter = iter2;
  ASSERT_EQ(*it, *iter);
}

TEST(TestVectorIteratorConst, IteratorConstTenth) {
  containers::Vector<int> V = {1, 2, 3, 4, 5};
  auto it = V.cbegin();
  auto it2 = V.cbegin();
  it2++;
  it2++;
  std::vector<int> V2 = {1, 2, 3, 4, 5};
  auto iter = V2.cbegin();
  auto iter2 = V2.cbegin();
  iter2++;
  iter2++;
  ASSERT_EQ(it < it2, iter < iter2);
}

TEST(TestVectorIteratorConst, IteratorConstEleventh) {
  containers::Vector<int> V = {1, 2, 3, 4, 5};
  auto it = V.cbegin();
  auto it2 = V.cbegin();
  it2++;
  it2++;
  std::vector<int> V2 = {1, 2, 3, 4, 5};
  auto iter = V2.cbegin();
  auto iter2 = V2.cbegin();
  iter2++;
  iter2++;
  ASSERT_EQ(it > it2, iter > iter2);
}

TEST(TestVectorIteratorConst, IteratorConstTwelfth) {
  containers::Vector<int> V = {1, 2, 3, 4, 5};
  auto it = V.cbegin();
  auto it2 = V.cbegin();
  it2++;
  it2++;
  std::vector<int> V2 = {1, 2, 3, 4, 5};
  auto iter = V2.cbegin();
  auto iter2 = V2.cbegin();
  iter2++;
  iter2++;
  ASSERT_EQ(it <= it2, iter < iter2);
}

TEST(TestVectorIteratorConst, IteratorConstThirteenth) {
  containers::Vector<int> V = {1, 2, 3, 4, 5};
  auto it = V.cbegin();
  auto it2 = V.cbegin();
  it2++;
  it2++;
  std::vector<int> V2 = {1, 2, 3, 4, 5};
  auto iter = V2.cbegin();
  auto iter2 = V2.cbegin();
  iter2++;
  iter2++;
  ASSERT_EQ(it >= it2, iter >= iter2);
}
