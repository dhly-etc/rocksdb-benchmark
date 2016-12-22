#ifndef ROCKSDB_BENCHMARK_ROCKSDB_INSTANCE_H
#define ROCKSDB_BENCHMARK_ROCKSDB_INSTANCE_H 1

#include <benchmark/ArangoComparator.h>
#include <benchmark/ArangoPrefixTransform.h>
#include <benchmark/Mutex.h>
#include <benchmark/MutexLocker.h>
#include <rocksdb/cache.h>
#include <rocksdb/db.h>
#include <rocksdb/options.h>
#include <rocksdb/slice_transform.h>
#include <rocksdb/table.h>
#include <cassert>
#include <iostream>
#include <string>

namespace benchmark {

class RocksDBInstance {
 private:
  static benchmark::Mutex _rocksDbMutex;
  static ArangoComparator* _comparator;
  static rocksdb::DB* _db;                      // single global instance
  static std::atomic<uint64_t> _instanceCount;  // number of active maps
  std::string _dbFolder;

 public:
  RocksDBInstance(std::string const& folder);
  ~RocksDBInstance();

  rocksdb::DB* db();
  ArangoComparator* comparator();

 private:
  rocksdb::Options generateOptions();
};
}  // namespace benchmark

#endif
