cmd_Release/md5cc.node := ln -f "Release/obj.target/md5cc.node" "Release/md5cc.node" 2>/dev/null || (rm -rf "Release/md5cc.node" && cp -af "Release/obj.target/md5cc.node" "Release/md5cc.node")
