local _class = {}

function class(super)
    local class_type = {}
    class_type.ctor = false

    class_type.super = super

    local vtbl = {}
    _class[class_type]=vtbl

    -- 当试图往class_type中添加成员时，存储到vtbl中
    setmetatable(class_type,{__newindex=
        function (table,key,value)
            vtbl[k] = v
        end
    })


    -- 如果元素在子类中找不到 则在父类中寻找并复制给vtbl然后返回
    if super then
        setmetatable(vtbl, {__index =
            function (t,k)
                local ret = _class[super][k]
                vtbl[k] = ret
                return ret
            end
        })
    end    

    class_type.new = function(...)
        local obj = {}
        do
            local create
            create = function (c,...)
                if c.super then
                    create(c.super,...)
                end
                if c.ctor then
                    c.ctor(obj,...)
                end
            end
            create(class_type,...)

        end

        setmetatable(obj,{__index=_class[class_type]})

        return obj -- 返回构造的对象
    end

    return class_type -- 只是返回一个类型

end