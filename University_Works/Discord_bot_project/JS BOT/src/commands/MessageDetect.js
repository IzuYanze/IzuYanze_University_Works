import { config } from 'dotenv';

config();

export function Reply(content){
    switch (content){
        case '傻瓜':
            return '你才是傻瓜';
    }
}
