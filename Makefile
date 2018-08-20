# ��Ҫ�ų���Ŀ¼
exclude_dirs := include bin third-party
# ȡ�õ�ǰ��Ŀ¼���Ϊ1������Ŀ¼����

DIRS := $(shell find . -maxdepth 1 -type d)
DIRS := $(basename $(patsubst ./%,%,$(DIRS)))
DIRS := $(filter-out $(exclude_dirs),$(DIRS))

.PHONY: release clean

release: 
	@for x in $(DIRS); \
  do \
    make -C $$x; \
  done

clean:
	@for x in $(DIRS); \
  do \
    make -C $$x $@; \
  done
